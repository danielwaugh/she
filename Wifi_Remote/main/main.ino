#include <ESP8266WiFi.h> 
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h" 

#define WLAN_SSID       "SHE_123456789" 
#define WLAN_PASS       "iamthebestintheworld" 
#define MQTT_SERVER     "192.168.5.1"  // give static address
#define MQTT_PORT       1883                    
#define MQTT_USERNAME   "" 
#define MQTT_PASSWORD   "" 

const int LED_1 = 12;   
const int LED_2 = 14;       
const int LED_3 = 16;

WiFiClient client; 

Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD); 

Adafruit_MQTT_Publish remoteSend = Adafruit_MQTT_Publish(&mqtt, MQTT_USERNAME "/she/remote_send"); 

Adafruit_MQTT_Subscribe remoteReceive = Adafruit_MQTT_Subscribe(&mqtt, MQTT_USERNAME "/she/remote_receive");


byte cols[] = {3,1};
const int colCount = sizeof(cols)/sizeof(cols[0]);
 
byte rows[] = {5,4,13};
const int rowCount = sizeof(rows)/sizeof(rows[0]);
 
byte buttonPress = 0;

int sleepCounter = 0;

int onMatrix[2][3] = { {0, 0, 0},{0, 0, 0} };  //all off

int prevMatrix[2][3] = { {0, 0, 0},{0, 0, 0} };

void WiFi_Connect();
void MQTT_Connect(); 
void MQTT_getData();
void Read_Matrix();
void Display_LEDS();
void Update_Database();

void setup() {
  WiFi_Connect();
  MQTT_Connect();
  MQTT_getData();
}

void loop() {
  if(!buttonPress) {
    Read_Matrix();
    Display_LEDS();
    sleepCounter += 1;
    if(sleepCounter > 3000)
    {
      ESP.deepSleep(0);
    }
  }
  else {
    sleepCounter = 0;
    Update_Database();
    for (int i = 0; i < 160; i++) {
      Display_LEDS();
    }
    buttonPress = 0;
  }
}

void WiFi_Connect() {
   WiFi.begin(WLAN_SSID, WLAN_PASS); 
   while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
 }
}

void MQTT_Connect(){ 
  mqtt.subscribe(&remoteReceive);
  int8_t ret; 
  if (mqtt.connected()) { 
    return; 
  } 
  uint8_t retries = 3; 
  while ((ret = mqtt.connect()) != 0) {
    mqtt.disconnect(); 
    delay(5000);  // wait 5 seconds 
    retries--; 
    if (retries == 0) { 
    while (1); 
    } 
 } 
}

void MQTT_getData() {
  byte flag = 0;
  remoteSend.publish("DATA");
  Adafruit_MQTT_Subscribe *subscription; 
  while ((subscription = mqtt.readSubscription()) || flag == 0) { 
   if (subscription == &remoteReceive) { 
      char * data = (char *)remoteReceive.lastread;
      if(data[0] == 'D'){
        if(data[1] == '1') {
          onMatrix[0][0] = 1;
          prevMatrix[0][0] = 1;
        }
        if(data[1] == '2') {
          onMatrix[0][0] = 2;
          prevMatrix[0][0] = 2;
        }
        if(data[2] == '1') {
          onMatrix[0][1] = 1;
          prevMatrix[0][1] = 1;
        }
        if(data[2] == '2') {
          onMatrix[0][1] = 2;
          prevMatrix[0][1] = 2;
        }
        if(data[3] == '1') {
          onMatrix[0][2] = 1;
          prevMatrix[0][2] = 1;
        }
        if(data[3] == '2') {
          onMatrix[0][2] = 2;
          prevMatrix[0][2] = 2;
        }
        if(data[4] == '1') {
          onMatrix[1][0] = 1;
          prevMatrix[1][0] = 1;
        }
        if(data[4] == '2') {
          onMatrix[1][0] = 2;
          prevMatrix[1][0] = 2;
        }
        if(data[5] == '1') {
          onMatrix[1][1] = 1;
          prevMatrix[1][1] = 1;
        }
        if(data[5] == '2') {
          onMatrix[1][1] = 2;
          prevMatrix[1][1] = 2;
        }
        if(data[6] == '1') {
          onMatrix[1][2] = 1;
          prevMatrix[1][2] = 1;
        }
        if(data[6] == '2') {
          onMatrix[1][2] = 2;
          prevMatrix[1][2] = 2;
        }
        flag = 1;
      }
    }
  }
}

void Read_Matrix() {
    for (int colIndex=0; colIndex < colCount; colIndex++) {
        for(int x=0; x<rowCount; x++) {
            pinMode(rows[x], INPUT);
          }
 
        for (int x=0; x<colCount; x++) {
            pinMode(cols[x], INPUT_PULLUP);
          }
        byte curCol = cols[colIndex];
        pinMode(curCol, OUTPUT);
        digitalWrite(curCol, LOW);
 
        for (int rowIndex=0; rowIndex < rowCount; rowIndex++) {
            byte rowCol = rows[rowIndex];
            pinMode(rowCol, INPUT_PULLUP);
            if(digitalRead(rowCol) == 0) {
              if(onMatrix[colIndex][rowIndex] != 2) {
                onMatrix[colIndex][rowIndex] ^= 1;
              }
              buttonPress = 1;
              break;
            }
            if(buttonPress) {
              break;
            }
            pinMode(rowCol, INPUT);
        }
        pinMode(curCol, INPUT);
    }
}

void Display_LEDS() {
  
  if(onMatrix[0][0] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, INPUT);      
  
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW); 
  }
  delayMicroseconds(500);
  pinMode(LED_1, INPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, INPUT);    
  if(onMatrix[1][0] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, INPUT);     
    pinMode(LED_3, OUTPUT);      
  
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_3, LOW);
  }
  delayMicroseconds(500);
  pinMode(LED_1, INPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, INPUT);    
  if(onMatrix[0][1] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, INPUT);      
  
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_1, LOW);
  }
  delayMicroseconds(500);
  pinMode(LED_1, INPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, INPUT);    
  if(onMatrix[1][1] == 1) {
    pinMode(LED_1, INPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, OUTPUT);      
  
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
  }
  delayMicroseconds(500);
  pinMode(LED_1, INPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, INPUT);    
  if(onMatrix[0][2] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, INPUT);     
    pinMode(LED_3, OUTPUT);      
  
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_1, LOW);
  }
  delayMicroseconds(500);
  pinMode(LED_1, INPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, INPUT);    
  if(onMatrix[1][2] == 1) {
    pinMode(LED_1, INPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, OUTPUT);      
  
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_2, LOW);
  }
  delayMicroseconds(500);
  pinMode(LED_1, INPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, INPUT);      
}

void Update_Database() {
  for(int row=0; row < 2; row++) {
    for(int col=0; col < 3; col++) {
      if (onMatrix[row][col] != prevMatrix[row][col]) {
        String temp = 'R' + String(row) + String(col) + String(onMatrix[row][col]);
        char * sender = (char *)temp.c_str();
        remoteSend.publish(sender);
        prevMatrix[row][col] = onMatrix[row][col];
      }
    }
  }
}
