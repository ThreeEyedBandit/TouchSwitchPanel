/*Offset temperature by 40 degress to allow negative temps to be displayed
Sensor PWM
0    5
1.5  35
5    65
45   200
*/
#include <arduino.h>
#include <WiFi.h>
#include <esp_now.h>
#include <lvgl.h>
#include <Adafruit_GFX.h>
#include <LovyanGFX.hpp>
#include <lgfx/v1/platforms/esp32s3/Panel_RGB.hpp>
#include <lgfx/v1/platforms/esp32s3/Bus_RGB.hpp>
#include "ui.h"
#include "dataStruct.h"
#include <APDS9930.h>

#define TFT_BL 2
#define ambientLightCheckInterval 250

uint8_t touch_Mac_Address[] = {0x30, 0xED, 0xA0, 0x2F, 0xC6, 0xB8}; //Touch Panel MAC
uint8_t eight_Relay_Address[] = {0x68, 0x25, 0xDD, 0xFA, 0x2C, 0x20}; //Eight Relay MAC

class LGFX : public lgfx::LGFX_Device
{
public:

  lgfx::Bus_RGB     _bus_instance;
  lgfx::Panel_RGB   _panel_instance;

  LGFX(void)
  {
    {
      auto cfg = _bus_instance.config();
      cfg.panel = &_panel_instance;
      
      cfg.pin_d0  = GPIO_NUM_8; // B0
      cfg.pin_d1  = GPIO_NUM_3;  // B1
      cfg.pin_d2  = GPIO_NUM_46;  // B2
      cfg.pin_d3  = GPIO_NUM_9;  // B3
      cfg.pin_d4  = GPIO_NUM_1;  // B4
      
      cfg.pin_d5  = GPIO_NUM_5;  // G0
      cfg.pin_d6  = GPIO_NUM_6; // G1
      cfg.pin_d7  = GPIO_NUM_7;  // G2
      cfg.pin_d8  = GPIO_NUM_15;  // G3
      cfg.pin_d9  = GPIO_NUM_16; // G4
      cfg.pin_d10 = GPIO_NUM_4;  // G5
      
      cfg.pin_d11 = GPIO_NUM_45; // R0
      cfg.pin_d12 = GPIO_NUM_48; // R1
      cfg.pin_d13 = GPIO_NUM_47; // R2
      cfg.pin_d14 = GPIO_NUM_21; // R3
      cfg.pin_d15 = GPIO_NUM_14; // R4

      cfg.pin_henable = GPIO_NUM_40;
      cfg.pin_vsync   = GPIO_NUM_41;
      cfg.pin_hsync   = GPIO_NUM_39;
      cfg.pin_pclk    = GPIO_NUM_0;
      cfg.freq_write  = 15000000;

      cfg.hsync_polarity    = 0;
      cfg.hsync_front_porch = 8;
      cfg.hsync_pulse_width = 4;
      cfg.hsync_back_porch  = 43;
      
      cfg.vsync_polarity    = 0;
      cfg.vsync_front_porch = 8;
      cfg.vsync_pulse_width = 4;
      cfg.vsync_back_porch  = 12;

      cfg.pclk_active_neg   = 1;
      cfg.de_idle_high      = 0;
      cfg.pclk_idle_high    = 0;

      _bus_instance.config(cfg);
    }
            {
      auto cfg = _panel_instance.config();
      cfg.memory_width  = 800;
      cfg.memory_height = 480;
      cfg.panel_width  = 800;
      cfg.panel_height = 480;
      cfg.offset_x = 0;
      cfg.offset_y = 0;
      _panel_instance.config(cfg);
    }
    _panel_instance.setBus(&_bus_instance);
    setPanel(&_panel_instance);

  }
};

LGFX lcd;

boolean blnTouched = false;
boolean firstPass = true;
unsigned long ambientLightCheckStart = millis();
int longTermBrightness;
int longTermBrightnessTarget;

#include "touch.h"

static uint32_t screenWidth;
static uint32_t screenHeight;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t disp_draw_buf[800 * 480 / 10];
static lv_disp_drv_t disp_drv;

esp_now_peer_info_t peerInfo;
APDS9930 sensor = APDS9930();

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);
void buildDisplay();
void updateDisplay();
void startESP_Now();
void initData();
int calcBrightnessTarget();

void setup()
{
  Serial.begin(115200);
  initData();
  buildDisplay();
  startESP_Now();

  sensor.init();
  sensor.enableProximitySensor(false);
  sensor.enableLightSensor(false);
}
void loop()
{
  lv_timer_handler_run_in_period(5);

  if(firstPass){
    longTermBrightness = calcBrightnessTarget();
    analogWrite(TFT_BL, longTermBrightness);
    esp_now_send(eight_Relay_Address, (uint8_t *) &currentData, sizeof(currentData));
    firstPass = false;
  }

  if(millis() - ambientLightCheckStart >= ambientLightCheckInterval){
    longTermBrightnessTarget = calcBrightnessTarget();
  
    if(longTermBrightness < longTermBrightnessTarget) longTermBrightness++;
    else if(longTermBrightness > longTermBrightnessTarget) longTermBrightness--;  

    analogWrite(TFT_BL, longTermBrightness);
    
    ambientLightCheckStart = millis();
  }

  if(blnTouched){
    esp_now_send(eight_Relay_Address, (uint8_t *) &currentData, sizeof(currentData));
    blnTouched = false;
  }
}
void updateDisplay(){
  lv_label_set_text_fmt(ui_OutTempDisplay, "%d°", currentData.outsideTemp);
  lv_label_set_text_fmt(ui_Button2Value, "%d p.s.i.", currentData.airPressure); 
  lv_label_set_text_fmt(ui_Button5Value, "%.1f V", float(currentData.batt2Voltage)/10);
  //lv_label_set_text_fmt(ui_AltitudeDisplay, "%d ft", currentData.gpsAltitude);
  //lv_label_set_text_fmt(ui_BearingLabel, "%d°", currentData.gpsCourse);

  lv_obj_set_style_bg_color(ui_Button1Indicator,currentData.Button1State ? lv_color_hex(0x00FF00) : lv_color_hex(0xFF0000),LV_PART_MAIN);
  lv_obj_set_style_bg_color(ui_Button2Indicator,currentData.Button2State ? lv_color_hex(0x00FF00) : lv_color_hex(0xFF0000),LV_PART_MAIN);
  lv_obj_set_style_bg_color(ui_Button3Indicator,currentData.Button3State ? lv_color_hex(0x00FF00) : lv_color_hex(0xFF0000),LV_PART_MAIN);
  lv_obj_set_style_bg_color(ui_Button4Indicator,currentData.Button4State ? lv_color_hex(0x00FF00) : lv_color_hex(0xFF0000),LV_PART_MAIN);
  lv_obj_set_style_bg_color(ui_Button5Indicator,currentData.Button5State ? lv_color_hex(0x00FF00) : lv_color_hex(0xFF0000),LV_PART_MAIN);
  lv_obj_set_style_bg_color(ui_Button6Indicator,currentData.Button6State ? lv_color_hex(0x00FF00) : lv_color_hex(0xFF0000),LV_PART_MAIN);
}
void startESP_Now(){
  WiFi.mode(WIFI_STA);
  
// Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, eight_Relay_Address, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));
}
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
}
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&currentData, incomingData, sizeof(currentData));
  updateDisplay();
}
int calcBrightnessTarget(){//int intTemp){
  float ambientLight;
  char tempStr[10];
  sensor.readAmbientLightLux(ambientLight);
  //lv_label_set_text_fmt(ui_Label2, "%s", dtostrf(ambientLight,6,2,tempStr));
  
  if(ambientLight >= 0 &&ambientLight < 2) 
  {return 5;}
  else if(ambientLight >= 2 && ambientLight < 5) 
  {return 35;}
  else if(ambientLight >= 5 &&ambientLight < 30) 
  {return 65;}
  else if(ambientLight >= 30 && ambientLight < 45)
  {return 110;}
  else if(ambientLight >= 45 && ambientLight < 90) 
  {return 200;}
  else {return 255;}
}
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint32_t w = (area->x2 - area->x1 + 1);
  uint32_t h = (area->y2 - area->y1 + 1);

#if (LV_COLOR_16_SWAP != 0)
 lcd.pushImageDMA(area->x1, area->y1, w, h,(lgfx::rgb565_t*)&color_p->full);
#else
  lcd.pushImageDMA(area->x1, area->y1, w, h,(lgfx::rgb565_t*)&color_p->full);//
#endif

  lv_disp_flush_ready(disp);
}
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  if (touch_touched())
  {
    data->state = LV_INDEV_STATE_PR;
    data->point.x = touch_last_x;
    data->point.y = touch_last_y;
  }
  else
  {
    blnTouched = false;
    data->state = LV_INDEV_STATE_REL;
  }
  delay(15);
}
void buildDisplay(){
  {
  lcd.begin();
  lcd.fillScreen(TFT_BLACK);
  delay(200);

  lv_init();

  delay(100);
  touch_init();

  screenWidth = lcd.width();
  screenHeight = lcd.height();

  lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, NULL, screenWidth * screenHeight / 10);
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &draw_buf;
  lv_disp_drv_register(&disp_drv);
  static lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);
  indev_drv.type = LV_INDEV_TYPE_POINTER;
  indev_drv.read_cb = my_touchpad_read;
  lv_indev_drv_register(&indev_drv);

  ui_init();
  lv_timer_handler();}

  lv_label_set_text_fmt(ui_Button1Label, "Front\nLights");
  lv_label_set_text_fmt(ui_Button2Label, "Air\nComp");
  lv_label_set_text_fmt(ui_Button3Label, "Front\nWinch");
  lv_label_set_text_fmt(ui_Button4Label, "Under\nLights");
  lv_label_set_text_fmt(ui_Button5Label, "Batt\nConnect");
  lv_label_set_text_fmt(ui_Button6Label, "Rear\nWinch"); 
}
void initData(){
  currentData.Button1State = false;
  currentData.Button2State = false;
  currentData.Button3State = false;
  currentData.Button4State = false;
  currentData.Button5State = false;
  currentData.Button6State = false;
  currentData.Button7State = false;
  currentData.Button8State = false;

  currentData.Button1Indicator = false;
  currentData.Button2Indicator = false;
  currentData.Button3Indicator = false;
  currentData.Button4Indicator = false;
  currentData.Button5Indicator = false;
  currentData.Button6Indicator = false;
}