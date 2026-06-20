/*
GPIO32: Controls Relay 1
GPIO33: Controls Relay 2
GPIO25: Controls Relay 3
GPIO26: Controls Relay 4
GPIO27: Controls Relay 5
GPIO14: Controls Relay 6
GPIO12: Controls Relay 7
GPIO13: Controls Relay 8
*/

#include <Arduino.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <WiFi.h>
#include <esp_now.h>
//#include <TinyGPSPlus.h>

uint8_t touch_Mac_Address[] = {0x30, 0xED, 0xA0, 0x2F, 0xC6, 0xB8}; //Touch Panel MAC
uint8_t eight_Relay_Address[] = {0x68, 0x25, 0xDD, 0xFA, 0x2C, 0x20}; //Eight Relay MAC

const int oneWireBus = 4;
const int airPressurePin = 35;  
const int batt2VoltagePin = 34;
const int checkForChangeInterval = 500;
const int measurementCheckDuration = 50;

OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

//TinyGPSPlus gps;

esp_now_peer_info_t peerInfo;

typedef struct transferedData {
    byte outsideTemp;
    byte airPressure;
    byte batt2Voltage;
    boolean Button1State;
    boolean Button2State;
    boolean Button3State;
    boolean Button4State;
    boolean Button5State;
    boolean Button6State;
    boolean Button7State;
    boolean Button8State;
    boolean Button1Indicator;
    boolean Button2Indicator;
    boolean Button3Indicator;
    boolean Button4Indicator;
    boolean Button5Indicator;
    boolean Button6Indicator;
} 
struct_message;

transferedData currentData;
transferedData storedData;
transferedData measurementData;

unsigned long checkForChangeStart = millis();
unsigned long measurementDurationStart = millis();

byte measurementCount = 0;

bool dataChanged = false;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);
void StartESP_Now();
void initData();
void sendData();

void setup() {
  Serial.begin(115200);
  //Serial2.begin(9600, SERIAL_8N1, 16, 17);

  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(32,currentData.Button1State);
  digitalWrite(33,currentData.Button2State);
  digitalWrite(25,currentData.Button3State);
  digitalWrite(26,currentData.Button4State);
  digitalWrite(27,currentData.Button5State);
  digitalWrite(14,currentData.Button6State);
  digitalWrite(12,currentData.Button7State); 
  digitalWrite(13,currentData.Button8State);

  initData();
  sensors.begin();
  StartESP_Now();
}
void loop() {
  /*while(Serial2.available() > 0){
    Serial1.println(Serial2.read());
    gps.encode(Serial2.read());
    if(gps.location.isUpdated()){
      if(gps.location.isValid()){
        currentData.gpsLatitude = gps.location.lat();
        currentData.gpsLongitude = gps.location.lng();
      }

      if(gps.speed.isValid()) currentData.gpsSpeed = int(gps.speed.mph());
      if(gps.altitude.isValid()) currentData.gpsAltitude = int(gps.altitude.feet());
      if(gps.course.isValid()) currentData.gpsCourse = int(gps.course.deg());

      sendData();

      Serial.println(" Alt: " + String(currentData.gpsAltitude) + " Course: " + String(currentData.gpsCourse));
    }
  }*/

  if(millis() - measurementDurationStart > measurementCheckDuration){
    measurementData.airPressure = analogRead(airPressurePin);
    measurementData.batt2Voltage = analogRead(batt2VoltagePin);

    measurementDurationStart = millis();
    measurementCount++;
  }

  if(millis() - checkForChangeStart > checkForChangeInterval){  
    //int tempAirPressure = analogRead(airPressurePin);
    //int tempBatt2Voltage = analogRead(batt2VoltagePin);
    
    //if(tempAirPressure < 215)tempAirPressure = 215;
    
    sensors.requestTemperatures(); currentData.outsideTemp = sensors.getTempFByIndex(0);
    
    measurementData.airPressure = measurementData.airPressure/measurementCount;
    measurementData.batt2Voltage = measurementData.batt2Voltage/measurementCount;
    
    //currentData.airPressure = map(tempAirPressure, 215, 3200, 0, 150);
    //currentData.batt2Voltage = map(tempBatt2Voltage, 10, 3720, 0, 143);

    currentData.airPressure = map(measurementData.airPressure, 215, 3200, 0, 150);
    currentData.batt2Voltage = map(measurementData.batt2Voltage, 10, 3720, 0, 143);

    if(currentData.outsideTemp != storedData.outsideTemp)dataChanged = true;
    if(currentData.airPressure != storedData.airPressure)dataChanged = true;
    if(currentData.batt2Voltage != storedData.batt2Voltage)dataChanged = true;

    if(dataChanged)sendData();
    
    checkForChangeStart = millis();

    measurementData.airPressure = 0;
    measurementData.batt2Voltage = 0;
    measurementCount = 0;
  }
}
void sendData(){
  esp_now_send(touch_Mac_Address, (uint8_t *) &currentData, sizeof(currentData));
  storedData = currentData;
  dataChanged = false;
}
void StartESP_Now(){
WiFi.mode(WIFI_STA);

  // Init ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);
  
  // Register peer
  memcpy(peerInfo.peer_addr, touch_Mac_Address, 6);
  peerInfo.channel = 0;  
  peerInfo.encrypt = false;
  
  // Add peer        
  if (esp_now_add_peer(&peerInfo) != ESP_OK){
    Serial.println("Failed to add peer");
    return;
  }
  // Register for a callback function that will be called when data is received
  esp_now_register_recv_cb(esp_now_recv_cb_t(OnDataRecv));

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

  esp_now_send(touch_Mac_Address, (uint8_t *) &currentData, sizeof(currentData));
}
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
}
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&currentData, incomingData, sizeof(currentData));

  digitalWrite(32, currentData.Button1State);
  digitalWrite(33, currentData.Button2State);
  digitalWrite(25, currentData.Button3State);
  digitalWrite(26, currentData.Button4State);
  digitalWrite(27, currentData.Button5State);
  digitalWrite(14, currentData.Button6State);
  digitalWrite(12, currentData.Button6State);
  digitalWrite(13, currentData.Button6State);

  currentData.Button1Indicator = currentData.Button1State;
  currentData.Button2Indicator = currentData.Button2State;
  currentData.Button3Indicator = currentData.Button3State;
  currentData.Button4Indicator = currentData.Button4State;
  currentData.Button5Indicator = currentData.Button5State;
  currentData.Button6Indicator = currentData.Button6State;

  storedData = currentData;

  esp_now_send(touch_Mac_Address, (uint8_t *) &currentData, sizeof(currentData));
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
