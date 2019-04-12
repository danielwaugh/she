#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#include "htmlpages.h"
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define MQTT_SERVER      "192.168.5.1"  // give static address
#define MQTT_PORT        1883
#define MQTT_USERNAME    ""
#define MQTT_PASSWORD    ""

WiFiClient client;

Adafruit_MQTT_Client mqtt(&client, MQTT_SERVER, MQTT_PORT, MQTT_USERNAME, MQTT_PASSWORD);

Adafruit_MQTT_Publish plug_send = Adafruit_MQTT_Publish(&mqtt, MQTT_USERNAME "/she/plug_send");

Adafruit_MQTT_Subscribe plug_receive = Adafruit_MQTT_Subscribe(&mqtt, MQTT_USERNAME "/she/plug_receive");

ESP8266WebServer server(80);

String currentSSID = "";
String currentPassword = "";
String tempSSID = "";
String tempPassword = "";
String temp = "";
bool currentMode = 0;    //station mode 0 - AP mode 1

int mqtt_notconnect = 0;

char sevenSegValue = '0';
char relayOutput = '0';

const int LED_A = 1;
const int LED_B = 3;
const int LED_C = 4;
const int LED_D = 5;
const int LED_E = 12;
const int LED_F = 13;
const int LED_G = 14;

int sevenSegPins[7] = {0, 0, 0, 0, 0, 0, 1};

void apMode();
void MQTT_connect();
void MQTT_Startup();

void webServerSetup();
void homePage();
void redirect1();
void configurePage1();
void configurePage2();
void redirect2();
void configurePage3();
void checkStatus();
void leaveSetup();

void Set_Seven_Seg();
void Seven_Seg();

void setup() {
  pinMode(16, OUTPUT);
  digitalWrite(16, HIGH);

  webServerSetup();

  WiFi.mode(WIFI_STA);

  pinMode(15, INPUT);

  MQTT_Startup();
}

void loop() {
  Adafruit_MQTT_Subscribe *subscription;
  byte flag = 0;
  while ((subscription = mqtt.readSubscription()) || flag == 0) {
    if (subscription == &plug_receive) {
      char * temp = (char *)plug_receive.lastread;
      if (temp[0] == 'T' && temp[1] == sevenSegValue) {
        relayOutput = temp[2];
        flag = 1;
      }
    }
    if (digitalRead(15) == 1) {
      for (int i = 0; i < 5; i++) {
        delay(1000);
        if ((digitalRead(15) == 1) and i == 4) {
          currentMode = 1;
          apMode();
        }
      }
    }
    Seven_Seg();
    MQTT_connect();
  }
}

void apMode() {
  WiFi.mode(WIFI_AP_STA);
  WiFi.softAP("SHE_PLUG");
  delay(5000);
  while (true) {
    server.handleClient();
    if (currentMode == 0 or digitalRead(15) == 1)
    {
      WiFi.mode(WIFI_STA);
      break;
    }
  }
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
      mqtt_notconnect = 1;
      break;
    }
  }
}

void MQTT_Startup() {
  MQTT_connect();
  if (!mqtt_notconnect) {
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
        if (temp[0] == 'S') {
          sevenSegValue = temp[1];
          relayOutput = temp[2];
          flag = 1;
        }
      }
    }
  }
  Set_Seven_Seg();
}

void Set_Seven_Seg() {
  if (sevenSegValue == '0') {
    int sevenSegPinsTemp[7] = {1, 1, 1, 1, 1, 1, 0};
    for (int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if (sevenSegValue == '1') {
    int sevenSegPinsTemp[7] = {0, 1, 1, 0, 0, 0, 0};
    for (int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if (sevenSegValue == '2') {
    int sevenSegPinsTemp[7] = {1, 1, 0, 1, 1, 0, 1};
    for (int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if (sevenSegValue == '3') {
    int sevenSegPinsTemp[7] = {1, 1, 1, 1, 0, 0, 1};
    for (int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if (sevenSegValue == '4') {
    int sevenSegPinsTemp[7] = {0, 1, 1, 0, 0, 1, 1};
    for (int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if (sevenSegValue == '5') {
    int sevenSegPinsTemp[7] = {1, 0, 1, 1, 0, 1, 1};
    for (int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if (sevenSegValue == '6') {
    int sevenSegPinsTemp[7] = {1, 0, 1, 1, 1, 1, 1};
    for (int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if (sevenSegValue == '7') {
    int sevenSegPinsTemp[7] = {1, 1, 1, 0, 0, 0, 0};
    for (int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if (sevenSegValue == '8') {
    int sevenSegPinsTemp[7] = {1, 1, 1, 1, 1, 1, 1};
    for (int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if (sevenSegValue == '9') {
    int sevenSegPinsTemp[7] = {1, 1, 1, 0, 0, 1, 1};
    for (int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
}

void Seven_Seg() {
  if (sevenSegPins[0] == 1) {
    pinMode(LED_A, OUTPUT);
    digitalWrite(LED_A, 0);
    delay(1);
    pinMode(LED_A, INPUT);
  }
  else {
    delay(1);
  }
  if (sevenSegPins[1] == 1) {
    pinMode(LED_B, OUTPUT);
    digitalWrite(LED_B, 0);
    delay(1);
    pinMode(LED_B, INPUT);
  }
  else {
    delay(1);
  }
  if (sevenSegPins[2] == 1) {
    pinMode(LED_C, OUTPUT);
    digitalWrite(LED_C, 0);
    delay(1);
    pinMode(LED_C, INPUT);
  }
  else {
    delay(1);
  }
  if (sevenSegPins[3] == 1) {
    pinMode(LED_D, OUTPUT);
    digitalWrite(LED_D, 0);
    delay(1);
    pinMode(LED_D, INPUT);
  }
  else {
    delay(1);
  }
  if (sevenSegPins[4] == 1) {
    pinMode(LED_E, OUTPUT);
    digitalWrite(LED_E, 0);
    delay(1);
    pinMode(LED_E, INPUT);
  }
  else {
    delay(1);
  }
  if (sevenSegPins[5] == 1) {
    pinMode(LED_F, OUTPUT);
    digitalWrite(LED_F, 0);
    delay(1);
    pinMode(LED_F, INPUT);
  }
  else {
    delay(1);
  }
  if (sevenSegPins[6] == 1) {
    pinMode(LED_G, OUTPUT);
    digitalWrite(LED_G, 0);
    delay(1);
    pinMode(LED_G, INPUT);
  }
  else {
    delay(1);
  }
  if (relayOutput == '1') {
    digitalWrite(16, LOW);
  }
  else {
    digitalWrite(16, HIGH);
  }
}

void homePage() {
  String htmlString1 = homePageHTML1;
  String htmlString2 = homePageHTML2;
  String picture = sheImage;
  server.send(200, "text/html", htmlString1 + picture + htmlString2);
}

void redirect1() {
  server.send(200, "text/html", "<HTML><head><meta http-equiv=\"refresh\" content=\"5;url=/configurePage1\" /></head><body><h1>redirecting</h1></body></HTML>");

  int numberOfNetworks = WiFi.scanNetworks();
  String openNetworks = "<form action=\"/configurePage2\" method=\"post\">";
  for (int i = 0; i < numberOfNetworks; i++)
  {
    openNetworks += "<label id=\"header\" class=\"container\">" + WiFi.SSID(i);
    openNetworks += "<input type=\"radio\" name=\"radio\" ";
    openNetworks += "value=\"" + WiFi.SSID(i) + "\" ";
    openNetworks += "\"><span class=\"checkmark\"></span></label><br><br>";
  }
  openNetworks += "<input id=\"submit\" type=\"submit\" value=\"Submit\" /></form>";

  temp = openNetworks;
}

void configurePage1() {
  String htmlString1 = configurePage1HTML1;
  String htmlString2 = configurePage1HTML2;
  String htmlString3 = configurePage1HTML3;
  String picture = sheImage;
  String openNetworks = temp;
  server.send(200, "text/html", htmlString1 + picture + htmlString2 + openNetworks + htmlString3);
}

void configurePage2() {
  String htmlString1 = configurePage2HTML1;
  String htmlString2 = configurePage2HTML2;
  String htmlString3 = configurePage2HTML3;
  String picture = sheImage;
  tempSSID = server.arg(0);
  String Intermediate = "<h3 id=\"header\">";
  if (server.args() > 0) {
    Intermediate += server.arg(0);
    Intermediate += "</h3><form action=\"/redirect2\" method=\"post\">";
    Intermediate += "<h4 id=\"header\">Enter Password</h4><input type=\"password\" name=\"password\"><br><br>";
    Intermediate += "<input id=\"submit\" type=\"submit\" value=\"Connect\" /></form>";
  }
  else {
    Intermediate += "ERROR</h3>";
  }

  server.send(200, "text/html", htmlString1 + picture + htmlString2 + Intermediate + htmlString3);
}

void redirect2() {
  server.send(200, "text/html", "<HTML><head><meta http-equiv=\"refresh\" content=\"8;url=/configurePage3\" /></head><body><h1>redirecting</h1></body></HTML>");
  String Intermediate = "<h3 id=\"header\">";
  if (server.args() > 0) {
    tempPassword = server.arg(0);
    WiFi.begin(tempSSID.c_str(), tempPassword.c_str());
    int i;
    for (i = 0; i < 7; i++) {
      if (WiFi.status() == WL_CONNECTED) {
        if (WiFi.SSID() == tempSSID) {
          Intermediate += "Your Smart Plug is already connected to this network</h3>";
          break;
        }
        Intermediate += "Your Smart Plug has successfully been added to the system</h3>";
        currentSSID = tempSSID;
        currentPassword = tempPassword;
        break;
      }
      delay(1000);
      if (i == 4) {
        Intermediate += "Could Not Connect to Network, Please Try again</h3>";
        break;
      }
    }
  }
  else {
    Intermediate += "ERROR</h3>";
  }
  Intermediate += "<form action=\"/\"><input id=\"submit\" type=\"submit\" value=\"Home Page\" /></form>";
  temp = Intermediate;
}

void configurePage3() {
  String htmlString1 = configurePage3HTML1;
  String htmlString2 = configurePage3HTML2;
  String picture = sheImage;
  String Intermediate = temp;
  server.send(200, "text/html", htmlString1 + picture + Intermediate + htmlString2);
}

void checkStatus() {
  String htmlString1 = checkStatusHTML1;
  String picture = sheImage;
  String Intermediate = "<h1 id=\"header\">Smart Plug Status</h1><br><h3 id=\"header\">Your Smart Plug is currently ";
  if (WiFi.status() == WL_CONNECTED) {
    Intermediate += "connected to the network " + WiFi.SSID();
  }
  else {
    Intermediate += "disconnected from the network";
  }
  Intermediate += "</h3><br><br><form action=\"/\"><input id=\"submit\" type=\"submit\" value=\"Home Page\" /></form></center><body></HTML>";
  server.send(200, "text/html", htmlString1 + picture + Intermediate);
}

void leaveSetup() {
  String htmlString1 = leavePageHTML1;
  String htmlString2 = leavePageHTML2;
  String picture = sheImage;
  server.send(200, "text/html", htmlString1 + picture + htmlString2);
  delay(1000);
  currentMode = 0;
}

void webServerSetup() {
  server.on("/", homePage);
  server.on("/redirect1", redirect1);
  server.on("/configurePage1", configurePage1);
  server.on("/configurePage2", configurePage2);
  server.on("/redirect2", redirect2);
  server.on("/configurePage3", configurePage3);
  server.on("/checkStatus", checkStatus);
  server.on("/leaveSetup", leaveSetup);

  server.begin();
}
