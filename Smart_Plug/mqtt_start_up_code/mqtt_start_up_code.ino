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

Adafruit_MQTT_Publish plug_send = Adafruit_MQTT_Publish(&mqtt, MQTT_USERNAME "/she/plug_send"); 

Adafruit_MQTT_Subscribe plug_receive = Adafruit_MQTT_Subscribe(&mqtt, MQTT_USERNAME "/she/plug_receive");

void MQTT_connect(); 
void MQTT_Startup();

char sevenSegValue = '0';

void setup() {
  Serial.begin(115200);
   WiFi.begin(WLAN_SSID, WLAN_PASS); 
   while (WiFi.status() != WL_CONNECTED) { 
   delay(500); 
 }
  MQTT_Startup();
}

void loop() {

}

void MQTT_connect() { 
  mqtt.subscribe(&plug_receive);
 int8_t ret; 
 if (mqtt.connected()) { 
   return; 
 } 
 uint8_t retries = 3; 
 while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected  
      mqtt.disconnect(); 
      delay(5000);  // wait 5 seconds 
      retries--; 
      if (retries == 0) { 
        // basically die and wait for WDT to reset me 
        while (1); 
      } 
 } 
}  

void MQTT_Startup() {
  MQTT_connect();
  
  plug_send.publish("START"); 
  delay(500);

  plug_send.publish(WiFi.localIP().toString().c_str());
  delay(500);

  plug_send.publish(WiFi.macAddress().c_str());
  delay(500);

  plug_send.publish("STOP");

  byte flag = 0;

  Adafruit_MQTT_Subscribe *subscription; 
  while ((subscription = mqtt.readSubscription()) || flag == 0) { 
   if (subscription == &plug_receive) { 
     char * temp = (char *)plug_receive.lastread;
     sevenSegValue = temp[0]; 
     Serial.println(sevenSegValue);
     flag = 1;
   } 
 } 
  
}
