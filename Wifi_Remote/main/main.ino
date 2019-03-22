const int LED_1 = 12;   
const int LED_2 = 14;       
const int LED_3 = 16;


byte cols[] = {3,1};
const int colCount = sizeof(cols)/sizeof(cols[0]);
 
byte rows[] = {5,4,13};
const int rowCount = sizeof(rows)/sizeof(rows[0]);
 
byte buttonPress = 0;

byte onMatrix[2][3] = { {0, 0, 0},{0, 0, 0} };  //all off

//void fetchMQTT() {
  //fetches the values of all the LEDs
//}

void setup() {
  for(int x=0; x<rowCount; x++) {
      pinMode(rows[x], INPUT);
  }
 
  for (int x=0; x<colCount; x++) {
      pinMode(cols[x], INPUT_PULLUP);
  }

 // fetchMQTT();
}

void readMatrix() {
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
              onMatrix[colIndex][rowIndex] ^= 1;
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

void displayLEDS() {
  
  if(onMatrix[0][0] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, INPUT);      
  
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW); 
  }
  delay(1);

  if(onMatrix[1][0] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, INPUT);     
    pinMode(LED_3, OUTPUT);      
  
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_3, LOW);
  }
  delay(1);

  if(onMatrix[0][1] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, INPUT);      
  
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_1, LOW);
  }
  delay(1);
  
  if(onMatrix[1][1] == 1) {
    pinMode(LED_1, INPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, OUTPUT);      
  
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
  }
  delay(1);

  if(onMatrix[0][2] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, INPUT);     
    pinMode(LED_3, OUTPUT);      
  
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_1, LOW);
  }
  delay(1);

  if(onMatrix[1][2] == 1) {
    pinMode(LED_1, INPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, OUTPUT);      
  
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_2, LOW);
  }
  delay(1);
  pinMode(LED_1, INPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, INPUT);      
}

//void updateMQTT() {
  //send value that was hit to database on hub
//}

void loop() {
  if(!buttonPress) {
    readMatrix();
    displayLEDS();
  }
  else {
    for (int i = 0; i < 80; i++) {
      displayLEDS();
    }
 //   updateMQTT();
    buttonPress = 0;
  }
}
