const int LED_1 = 14;   
const int LED_2 = 12;       
const int LED_3 = 13;
const int LED_4 = 5; 

byte rows[] = {5,1,3};
const int rowCount = sizeof(rows)/sizeof(rows[0]);
 
// JP2 and JP3 are outputs
byte cols[] = {14,12,13};
const int colCount = sizeof(cols)/sizeof(cols[0]);
 
byte buttonPress = 0;

byte onMatrix[3][3] = { {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};  //all off

//void fetchMQTT() {
  //fetches the values of all the LEDs
//}

void setup() {
  pinMode(4, OUTPUT);
  digitalWrite(4, LOW);
 
  for(int x=0; x<rowCount; x++) {
      pinMode(rows[x], INPUT);
  }
 
  for (int x=0; x<colCount; x++) {
      pinMode(cols[x], INPUT_PULLUP);
  }

 // fetchMQTT();
}

void readMatrix() {
  digitalWrite(4, HIGH);
    for (int colIndex=0; colIndex < colCount; colIndex++) {
        byte curCol = cols[colIndex];
        pinMode(curCol, OUTPUT);
        digitalWrite(curCol, LOW);
 
        for (int rowIndex=0; rowIndex < rowCount; rowIndex++) {
            byte rowCol = rows[rowIndex];
            pinMode(rowCol, INPUT_PULLUP);
            if(digitalRead(rowCol) == 0) {
              onMatrix[colIndex][rowIndex] ^= 1;
              buttonPress = 1;
            }
            pinMode(rowCol, INPUT);
        }
        pinMode(curCol, INPUT);
    }
  digitalWrite(4, LOW);
}

void displayLEDS() {
  
  if(onMatrix[0][0] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, INPUT);      
    pinMode(LED_4, INPUT); 
  
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_2, LOW);
  }
  delay(1);
    
  if(onMatrix[1][0] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, INPUT);     
    pinMode(LED_3, OUTPUT);      
    pinMode(LED_4, INPUT); 
  
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_3, LOW);
  } 
  delay(1);

  if(onMatrix[2][0] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, INPUT);     
    pinMode(LED_3, INPUT);      
    pinMode(LED_4, OUTPUT); 
  
    digitalWrite(LED_1, HIGH);
    digitalWrite(LED_4, LOW);
  } 
  delay(1);

  if(onMatrix[0][1] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, INPUT);      
    pinMode(LED_4, INPUT); 
  
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_1, LOW);
  } 
  delay(1);

  if(onMatrix[1][1] == 1) {
    pinMode(LED_1, INPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, OUTPUT);      
    pinMode(LED_4, INPUT); 
  
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_3, LOW);
  } 
  delay(1);

  if(onMatrix[2][1] == 1) {
    pinMode(LED_1, INPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, INPUT);      
    pinMode(LED_4, OUTPUT); 
  
    digitalWrite(LED_2, HIGH);
    digitalWrite(LED_4, LOW);
  } 
  delay(1);

  if(onMatrix[0][2] == 1) {
    pinMode(LED_1, OUTPUT);    
    pinMode(LED_2, INPUT);     
    pinMode(LED_3, OUTPUT);      
    pinMode(LED_4, INPUT); 
  
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_1, LOW);
  } 
  delay(1);

  if(onMatrix[1][2] == 1) {
    pinMode(LED_1, INPUT);    
    pinMode(LED_2, OUTPUT);     
    pinMode(LED_3, OUTPUT);      
    pinMode(LED_4, INPUT); 
  
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_2, LOW); 
  } 
  delay(1);
  
  if(onMatrix[2][2] == 1) {
    pinMode(LED_1, INPUT);    
    pinMode(LED_2, INPUT);     
    pinMode(LED_3, OUTPUT);      
    pinMode(LED_4, OUTPUT); 
  
    digitalWrite(LED_3, HIGH);
    digitalWrite(LED_4, LOW); 
  } 
  delay(1);

  for(int x=0; x<rowCount; x++) {
      pinMode(rows[x], INPUT);
  }
 
  for (int x=0; x<colCount; x++) {
      pinMode(cols[x], INPUT_PULLUP);
  }
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
    for (int i = 0; i < 1500; i++) {
      displayLEDS();
    }
 //   updateMQTT();
    buttonPress = 0;
  }
}
