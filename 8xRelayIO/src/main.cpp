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

#define checkForChangeInterval 100
#define watchdogInterval 2000

uint8_t touch_Mac_Address[] = {0x30, 0xED, 0xA0, 0x2F, 0xC6, 0xB8}; //Touch Panel MAC
uint8_t eight_Relay_Address[] = {0x68, 0x25, 0xDD, 0xFA, 0x2C, 0x20}; //Eight Relay MAC

const int oneWireBus = 4;
const int airPressurePin = 35;  

OneWire oneWire(oneWireBus);
DallasTemperature sensors(&oneWire);

esp_now_peer_info_t peerInfo;

typedef struct transferedData {
    byte outsideTemp;
    byte airPressure;
    boolean Button1 = false;
    boolean Button2 = false;
    boolean Button3 = false;
    boolean Button4 = false;
    boolean Button5 = false;
    boolean Button6 = false;
    boolean Button7 = false;
    boolean Button8 = false;
} 
struct_message;

transferedData TXdData;
transferedData RXdData;
transferedData CurrentData;

unsigned long checkForChangeStart = millis();
unsigned long watchdogStart = millis();

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status);
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len);
void StartESP_Now();

void setup() {
  Serial.begin(9600);

  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(14, OUTPUT);

  digitalWrite(32,CurrentData.Button1);
  digitalWrite(33,CurrentData.Button2);
  digitalWrite(25,CurrentData.Button3);
  digitalWrite(26,CurrentData.Button4);
  digitalWrite(27,CurrentData.Button5);
  digitalWrite(14,CurrentData.Button6);

  sensors.begin();
  StartESP_Now();
}

void loop() {
  if(millis() - watchdogStart > watchdogInterval){
    CurrentData.Button1 = false;
    CurrentData.Button2 = false;
    CurrentData.Button3 = false;
    CurrentData.Button4 = false;
    CurrentData.Button5 = false;
    CurrentData.Button6 = false;

    digitalWrite(32, CurrentData.Button1);
    digitalWrite(33, CurrentData.Button2);
    digitalWrite(25, CurrentData.Button3);
    digitalWrite(26, CurrentData.Button4);
    digitalWrite(27, CurrentData.Button5);
    digitalWrite(14, CurrentData.Button6);
  }

  if(millis() - checkForChangeStart > checkForChangeInterval){  
    bool dataChanged = false;
    int tempAirPressure = analogRead(airPressurePin);
    Serial.println(tempAirPressure);
    if(tempAirPressure < 215)tempAirPressure = 215;
    
    sensors.requestTemperatures(); CurrentData.outsideTemp = sensors.getTempFByIndex(0);
    
    CurrentData.airPressure = map(tempAirPressure, 215, 3200, 0, 150);

    if(CurrentData.outsideTemp != TXdData.outsideTemp){
      TXdData.outsideTemp = CurrentData.outsideTemp;
      dataChanged = true;
    }

    if(CurrentData.airPressure != TXdData.airPressure){
      TXdData.airPressure = CurrentData.airPressure;
      dataChanged = true;
    }

    TXdData.outsideTemp = CurrentData.outsideTemp;
    TXdData.airPressure = CurrentData.airPressure;
    Serial.print(TXdData.Button1);Serial.print(";");
    Serial.print(TXdData.Button1);Serial.print(";");
    Serial.print(TXdData.Button1);Serial.print(";");
    Serial.print(TXdData.Button1);Serial.print(";");
    Serial.print(TXdData.Button1);Serial.print(";");
    Serial.print(TXdData.Button1);Serial.print(";");
    Serial.print(TXdData.outsideTemp); Serial.print(";");
    Serial.println(CurrentData.airPressure);
    
   
    if(dataChanged)esp_now_send(touch_Mac_Address, (uint8_t *) &TXdData, sizeof(TXdData));

    checkForChangeStart = millis();
  }
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
   esp_now_send(touch_Mac_Address, (uint8_t *) &TXdData, sizeof(TXdData));
}
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
}
void OnDataRecv(const uint8_t * mac, const uint8_t *incomingData, int len) {
  memcpy(&RXdData, incomingData, sizeof(RXdData));

  if(RXdData.Button1 != CurrentData.Button1){
    CurrentData.Button1 = RXdData.Button1;
  }
  if(RXdData.Button2 != CurrentData.Button2){
    CurrentData.Button2 = RXdData.Button2;
  }
  if(RXdData.Button3 != CurrentData.Button3){
    CurrentData.Button3 = RXdData.Button3;
  }
  if(RXdData.Button4 != CurrentData.Button4){
    CurrentData.Button4 = RXdData.Button4;
  }
  if(RXdData.Button5 != CurrentData.Button5){
    CurrentData.Button5 = RXdData.Button5;
  }
  if(RXdData.Button6 != CurrentData.Button6){
    CurrentData.Button6 = RXdData.Button6;
  }

  digitalWrite(32, CurrentData.Button1);
  digitalWrite(33, CurrentData.Button2);
  digitalWrite(25, CurrentData.Button3);
  digitalWrite(26, CurrentData.Button4);
  digitalWrite(27, CurrentData.Button5);
  digitalWrite(14, CurrentData.Button6);

  esp_now_send(touch_Mac_Address, (uint8_t *) &TXdData, sizeof(TXdData));

  watchdogStart = millis();
}
