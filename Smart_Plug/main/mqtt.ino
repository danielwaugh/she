/*WiFiClient client;  

Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD); 

Adafruit_MQTT_Publish autoSetup = Adafruit_MQTT_Publish(&mqtt, MQTT_USERNAME "/setup/plug"); 

void MQTT_connect();

void setupPlugHub() {
  Adafruit_MQTT_Publish autoSetup = Adafruit_MQTT_Publish(&mqtt, MQTT_USERNAME "/setup/plug"); 

  mqtt.subscribe(autoSetup); 

  MQTT_connect(); 
}

void loop() { 
 MQTT_connect(); 
 // this is our 'wait for incoming subscription packets' busy subloop 
 // try to spend your time here 
 // Here its read the subscription 
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
// Function to connect and reconnect as necessary to the MQTT server. 
void MQTT_connect() { 
 int8_t ret; 
 // Stop if already connected. 
 if (mqtt.connected()) { 
   return; 
 } 
 int retries = 3; 
 while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected  
      mqtt.disconnect(); 
      delay(5000);  // wait 5 seconds 
      retries--; 
      if (retries == 0) { 
        break;
      } 
 }  
}  */
