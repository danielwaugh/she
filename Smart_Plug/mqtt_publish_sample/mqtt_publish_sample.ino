#include <ESP8266WiFi.h> 
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h" 
/************************* WiFi Access Point *********************************/ 
#define WLAN_SSID       "SHE_123456789" 
#define WLAN_PASS       "iamthebestintheworld" 
#define MQTT_SERVER      "192.168.5.1"  // give static address
#define MQTT_PORT         1883                    
#define MQTT_USERNAME    "" 
#define MQTT_PASSWORD         "" 

WiFiClient client; 

Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD); 

Adafruit_MQTT_Publish pi_led = Adafruit_MQTT_Publish(&mqtt, MQTT_USERNAME "/leds/pi"); 

Adafruit_MQTT_Subscribe esp8266_led = Adafruit_MQTT_Subscribe(&mqtt, MQTT_USERNAME "/leds/esp8266"); 

void MQTT_connect(); 

int flag = 1;

void setup() { 
 WiFi.begin(WLAN_SSID, WLAN_PASS); 
 while (WiFi.status() != WL_CONNECTED) { 
   delay(500); 
 }
} 

void loop() { 
 MQTT_connect();
  if(flag) {
    pi_led.publish("ON"); 

    delay(500);

    pi_led.publish(WiFi.localIP().toString().c_str());

    delay(500);

    pi_led.publish(WiFi.macAddress().c_str());

    delay(500);

    pi_led.publish("OFF");
    flag = 0;
  }
} 
void MQTT_connect() { 
 int8_t ret; 
 if (mqtt.connected()) { 
   return; 
 } 
 uint8_t retries = 3; 
 while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected 
      Serial.println(mqtt.connectErrorString(ret)); 
      Serial.println("Retrying MQTT connection in 5 seconds..."); 
      mqtt.disconnect(); 
      delay(5000);  // wait 5 seconds 
      retries--; 
      if (retries == 0) { 
        // basically die and wait for WDT to reset me 
        while (1); 
      } 
 } 
}  
