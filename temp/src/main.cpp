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

#define TFT_BL 2

//lv_label_set_text(ui_OutTempDisplay,"50");
//lv_arc_set_value(ui_OutTempGauge,50);
//lv_label_set_text_fmt(ui_DebugLog, "%d", blnFrontLights);

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

#include "touch.h"

static uint32_t screenWidth;
static uint32_t screenHeight;
static lv_disp_draw_buf_t draw_buf;
static lv_color_t disp_draw_buf[800 * 480 / 10];
static lv_disp_drv_t disp_drv;

esp_now_peer_info_t peerInfo;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);
void buildDisplay();
void updateDisplay();
void startESP_Now();

void setup()
{
  Serial.begin(9600);

  buildDisplay();
  startESP_Now();
}

void loop()
{
  lv_timer_handler_run_in_period(5);

  if(CurrentData.Button1 != TXdData.Button1){
    TXdData.Button1 = CurrentData.Button1;
    esp_now_send(eight_Relay_Address, (uint8_t *) &TXdData, sizeof(TXdData));
  }
  if(CurrentData.Button2 != TXdData.Button2){
    TXdData.Button2 = CurrentData.Button2;
    esp_now_send(eight_Relay_Address, (uint8_t *) &TXdData, sizeof(TXdData));
  }
  if(CurrentData.Button3 != TXdData.Button3){
    TXdData.Button3 = CurrentData.Button3;
    esp_now_send(eight_Relay_Address, (uint8_t *) &TXdData, sizeof(TXdData));
  }
  if(CurrentData.Button4 != TXdData.Button4){
    TXdData.Button4 = CurrentData.Button4;
    esp_now_send(eight_Relay_Address, (uint8_t *) &TXdData, sizeof(TXdData));
  }
  if(CurrentData.Button5 != TXdData.Button5){
    TXdData.Button5 = CurrentData.Button5;
    esp_now_send(eight_Relay_Address, (uint8_t *) &TXdData, sizeof(TXdData));
  }
  if(CurrentData.Button6 != TXdData.Button6){
    TXdData.Button6 = CurrentData.Button6;
    esp_now_send(eight_Relay_Address, (uint8_t *) &TXdData, sizeof(TXdData));
  }
}

void updateDisplay(){
  lv_label_set_text_fmt(ui_OutTempDisplay, "%d°", RXdData.outsideTemp);
  lv_arc_set_value(ui_OutTempGauge, RXdData.outsideTemp);
  lv_label_set_text_fmt(ui_AirPressureDisplay, "%d", RXdData.airPressure);
  lv_arc_set_value(ui_AirPressureGauge, RXdData.airPressure);   
}

void startESP_Now(){
  WiFi.mode(WIFI_STA);
  
  /*
  WiFi.begin();

  Serial.print("[DEFAULT] ESP32 Board MAC Address: ");
  uint8_t baseMac[6];
  esp_err_t ret = esp_wifi_get_mac(WIFI_IF_STA, baseMac);
  if (ret == ESP_OK) {
    Serial.printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                  baseMac[0], baseMac[1], baseMac[2],
                  baseMac[3], baseMac[4], baseMac[5]);
  }
  while(true){}
  */
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

  esp_now_send(eight_Relay_Address, (uint8_t *) &TXdData, sizeof(TXdData));
}
// Callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
}
// Callback when data is received
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&RXdData, incomingData, sizeof(RXdData));
  updateDisplay();
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
  #ifdef TFT_BL
    analogWrite(TFT_BL, 255);
  #endif

  ui_init();
  lv_timer_handler();}

  lv_label_set_text_fmt(ui_Button1Label, "Front\nLights");
  lv_label_set_text_fmt(ui_Button2Label, "Air\nComp");
  lv_label_set_text_fmt(ui_Button3Label, "Front\nWinch");
  lv_label_set_text_fmt(ui_Button4Label, "Under\nLights");
  lv_label_set_text_fmt(ui_Button5Label, "Batt\nConnect");
  lv_label_set_text_fmt(ui_Button6Label, "Rear\nWinch"); 
	
  if(CurrentData.Button1){
    lv_obj_set_style_bg_color(ui_Button1Indicator,lv_color_hex(0x00FF00),LV_PART_MAIN);
  }
  else{
    lv_obj_set_style_bg_color(ui_Button1Indicator,lv_color_hex(0xFF0000),LV_PART_MAIN);
  }

    if(CurrentData.Button2){
    lv_obj_set_style_bg_color(ui_Button2Indicator,lv_color_hex(0x00FF00),LV_PART_MAIN);
  }
  else{
    lv_obj_set_style_bg_color(ui_Button2Indicator,lv_color_hex(0xFF0000),LV_PART_MAIN);
  }

  if(CurrentData.Button3){
    lv_obj_set_style_bg_color(ui_Button3Indicator,lv_color_hex(0x00FF00),LV_PART_MAIN);
  }
  else{
    lv_obj_set_style_bg_color(ui_Button3Indicator,lv_color_hex(0xFF0000),LV_PART_MAIN);
  }

  if(CurrentData.Button4){
    lv_obj_set_style_bg_color(ui_Button4Indicator,lv_color_hex(0x00FF00),LV_PART_MAIN);
  }
  else{
    lv_obj_set_style_bg_color(ui_Button4Indicator,lv_color_hex(0xFF0000),LV_PART_MAIN);
  }

  if(CurrentData.Button5){
    lv_obj_set_style_bg_color(ui_Button5Indicator,lv_color_hex(0x00FF00),LV_PART_MAIN);
  }
  else{
    lv_obj_set_style_bg_color(ui_Button5Indicator,lv_color_hex(0xFF0000),LV_PART_MAIN);
  }

  if(CurrentData.Button6){
    lv_obj_set_style_bg_color(ui_Button6Indicator,lv_color_hex(0x00FF00),LV_PART_MAIN);
  }
  else{
    lv_obj_set_style_bg_color(ui_Button6Indicator,lv_color_hex(0xFF0000),LV_PART_MAIN);
  }
}
