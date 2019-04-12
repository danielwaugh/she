#include <ESP8266WiFi.h> 
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h" 
/************************* WiFi Access Point *********************************/ 
#define WLAN_SSID       "SHE_123456789" 
#define WLAN_PASS       "iamthebestintheworld"
#define MQTT_SERVER     "192.168.5.1"  // give static address
#define MQTT_PORT       1883                    
#define MQTT_USERNAME   "" 
#define MQTT_PASSWORD   "" 

WiFiClient client; 

Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD); 

Adafruit_MQTT_Publish pi_led = Adafruit_MQTT_Publish(&mqtt, MQTT_USERNAME "/leds/pi"); 

Adafruit_MQTT_Subscribe esp8266_led = Adafruit_MQTT_Subscribe(&mqtt, MQTT_USERNAME "/leds/esp8266"); 

void MQTT_connect(); 

void setup() { 
 pinMode(16, OUTPUT);
 WiFi.begin(WLAN_SSID, WLAN_PASS); 
 while (WiFi.status() != WL_CONNECTED) { 
   delay(500); 
 } 

 mqtt.subscribe(&esp8266_led); 
} 
uint32_t x=0; 
void loop() { 

 MQTT_connect(); 

 Adafruit_MQTT_Subscribe *subscription; 
 while ((subscription = mqtt.readSubscription())) { 
   if (subscription == &esp8266_led) { 
     Serial.print(F("Got: ")); 
     Serial.println((char *)esp8266_led.lastread); 
     if (strcmp((char *)esp8266_led.lastread, "ON") == 0)
     {
      digitalWrite(12, HIGH);
     }
     if (strcmp((char *)esp8266_led.lastread, "OFF") == 0)
     {
      digitalWrite(12, LOW);
     }
   } 
 } 
} 

void MQTT_connect() { 
 int8_t ret; 
 if (mqtt.connected()) { 
   return; 
 } 
 uint8_t retries = 3; 
 while ((ret = mqtt.connect()) != 0) {
      mqtt.disconnect(); 
      delay(5000);
      retries--; 
      if (retries == 0) { 
        while (1); 
      } 
 } 
}  
