const int LED_A = 1;   
const int LED_B = 3;       
const int LED_C = 4;
const int LED_D = 5;   
const int LED_E = 12;       
const int LED_F = 13;
const int LED_G = 14;

int sevenSegPins[7] = {0,0,0,0,0,0,7};

void Set_Seven_Seg(int number) {
  if(number == 0) {
    int sevenSegPinsTemp[7] = {1,1,1,1,1,1,0};
    for(int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if(number == 1) {
    int sevenSegPinsTemp[7] = {0,1,1,0,0,0,0};
    for(int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if(number == 2) {
    int sevenSegPinsTemp[7] = {1,1,0,1,1,0,1};
    for(int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if(number == 3) {
    int sevenSegPinsTemp[7] = {1,1,1,1,0,0,1};
    for(int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if(number == 4) {
    int sevenSegPinsTemp[7] = {0,1,1,0,0,1,1};
    for(int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if(number == 5) {
    int sevenSegPinsTemp[7] = {1,0,1,1,0,1,1};
    for(int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if(number == 6) {
    int sevenSegPinsTemp[7] = {1,0,1,1,1,1,1};
    for(int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if(number == 7) {
    int sevenSegPinsTemp[7] = {1,1,1,0,0,0,0};
    for(int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if(number == 8) {
    int sevenSegPinsTemp[7] = {1,1,1,1,1,1,1};
    for(int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
  if(number == 9) {
    int sevenSegPinsTemp[7] = {1,1,1,0,0,1,1};
    for(int i = 0; i < 7; i++) {
      sevenSegPins[i] = sevenSegPinsTemp[i];
    }
  }
}

void Seven_Seg() {
  if(sevenSegPins[0] == 1) {
    pinMode(LED_A, OUTPUT);
    digitalWrite(LED_A, 0);
    delay(1);
    pinMode(LED_A, INPUT);
  }
  else {delay(1);}
  if(sevenSegPins[1] == 1) {
    pinMode(LED_B, OUTPUT);
    digitalWrite(LED_B, 0);
    delay(1);
    pinMode(LED_B, INPUT);
  }
  else {delay(1);}
  if(sevenSegPins[2] == 1) {
    pinMode(LED_C, OUTPUT);
    digitalWrite(LED_C, 0);
    delay(1);
    pinMode(LED_C, INPUT);
  }
  else {delay(1);}
  if(sevenSegPins[3] == 1) {
    pinMode(LED_D, OUTPUT);
    digitalWrite(LED_D, 0);
    delay(1);
    pinMode(LED_D, INPUT);
  }
  else {delay(1);}
  if(sevenSegPins[4] == 1) {
    pinMode(LED_E, OUTPUT);
    digitalWrite(LED_E, 0);
    delay(1);
    pinMode(LED_E, INPUT);
  }
  else {delay(1);}
  if(sevenSegPins[5] == 1) {
    pinMode(LED_F, OUTPUT);
    digitalWrite(LED_F, 0);
    delay(1);
    pinMode(LED_F, INPUT);
  }
  else {delay(1);}
  if(sevenSegPins[6] == 1) {
    pinMode(LED_G, OUTPUT);
    digitalWrite(LED_G, 0);
    delay(1);
    pinMode(LED_G, INPUT);
  }    
  else {delay(1);}    
}

void setup() {
  pinMode(LED_A, INPUT);
  pinMode(LED_B, INPUT);
  pinMode(LED_C, INPUT);
  pinMode(LED_D, INPUT);
  pinMode(LED_E, INPUT);
  pinMode(LED_F, INPUT);
  pinMode(LED_G, INPUT);
}

void loop() {
  Set_Seven_Seg(0);
  for(int i = 0; i < 150; i++) {
    Seven_Seg();
  }
  Set_Seven_Seg(1);
  for(int i = 0; i < 150; i++) {
    Seven_Seg();
  }
  Set_Seven_Seg(2);
  for(int i = 0; i < 150; i++) {
    Seven_Seg();
  }
  Set_Seven_Seg(3);
  for(int i = 0; i < 150; i++) {
    Seven_Seg();
  }
  Set_Seven_Seg(4);
  for(int i = 0; i < 150; i++) {
    Seven_Seg();
  }
  Set_Seven_Seg(5);
  for(int i = 0; i < 150; i++) {
    Seven_Seg();
  }
  Set_Seven_Seg(6);
  for(int i = 0; i < 150; i++) {
    Seven_Seg();
  }
  Set_Seven_Seg(7);
  for(int i = 0; i < 150; i++) {
    Seven_Seg();
  }
  Set_Seven_Seg(8);
  for(int i = 0; i < 150; i++) {
    Seven_Seg();
  }
  Set_Seven_Seg(9);
  for(int i = 0; i < 150; i++) {
    Seven_Seg();
  }
}
