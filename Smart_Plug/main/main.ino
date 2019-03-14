#include <ESP8266WiFi.h> 
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "htmlpages.h"
//#include "Adafruit_MQTT.h"
//#include "Adafruit_MQTT_Client.h"
//#include "define.h"

#define MQTT_SERVER      "192.168.5.1"  // give static address
#define MQTT_PORT        1883                    
#define MQTT_USERNAME    "" 
#define MQTT_PASSWORD    "" 

ESP8266WebServer server(80);

String currentSSID = "";
String currentPassword = "";
String tempSSID = "";
String tempPassword = "";
String temp = "";
bool currentMode = 0;    //station mode 0 - AP mode 1

void apMode() {
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP("SHE_PLUG");
  delay(5000);
  while(true) {
    server.handleClient();
    if(currentMode == 0 or digitalRead(15) == 1)
    {
      digitalWrite(12, LOW);
      WiFi.mode(WIFI_STA);
      break;
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  webServerSetup();

  WiFi.mode(WIFI_STA);

  pinMode(15, INPUT);
  pinMode(12, OUTPUT);
}

void loop() {
    if(digitalRead(15) == 1) {
      int i;
      for(i = 0; i < 5; i++) {
        delay(1000);
        if((digitalRead(15) == 1) and i == 4) {
          digitalWrite(12, HIGH);
          currentMode = 1;
          apMode();
        }
      }
    }
}
