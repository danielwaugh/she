// Keyboard Matrix Tutorial Example
// baldengineer.com
// CC BY-SA 4.0
  const int LED_1 = 14;   
const int LED_2 = 12;       
const int LED_3 = 13;
const int LED_4 = 5; 
// JP1 is an input
byte rows[] = {5,1,3};
const int rowCount = sizeof(rows)/sizeof(rows[0]);
 
// JP2 and JP3 are outputs
byte cols[] = {14,12,13};
const int colCount = sizeof(cols)/sizeof(cols[0]);
 
byte keys[colCount][rowCount];
 
void setup() {
    pinMode(4, OUTPUT);
    digitalWrite(4, HIGH);
 
    for(int x=0; x<rowCount; x++) {
        pinMode(rows[x], INPUT);
    }
 
    for (int x=0; x<colCount; x++) {
        pinMode(cols[x], INPUT_PULLUP);
    }
}
 
void readMatrix() {
    for (int colIndex=0; colIndex < colCount; colIndex++) {
        byte curCol = cols[colIndex];
        pinMode(curCol, OUTPUT);
        digitalWrite(curCol, LOW);
 
        for (int rowIndex=0; rowIndex < rowCount; rowIndex++) {
            byte rowCol = rows[rowIndex];
            pinMode(rowCol, INPUT_PULLUP);
            keys[colIndex][rowIndex] = digitalRead(rowCol);
            pinMode(rowCol, INPUT);
        }
        pinMode(curCol, INPUT);
    }
}
 
void printMatrix() {
    for (int rowIndex=0; rowIndex < rowCount; rowIndex++) {
        if (rowIndex < 10)
            Serial.print(F("0"));
        Serial.print(rowIndex); Serial.print(F(": "));
 
        for (int colIndex=0; colIndex < colCount; colIndex++) {  
            Serial.print(keys[colIndex][rowIndex]);
            if (colIndex < colCount)
                Serial.print(F(", "));
        }   
        Serial.println("");
    }
    Serial.println("");
}
 
void loop() {
    readMatrix();
    if(keys[2][1] == 0){
      digitalWrite(4, LOW);
      pinMode(LED_1, OUTPUT);    
      pinMode(LED_2, INPUT);     
      pinMode(LED_3, INPUT);      
      pinMode(LED_4, OUTPUT); 

      digitalWrite(LED_1, HIGH);
      digitalWrite(LED_4, LOW);
      delay(5000);
      digitalWrite(4, HIGH);
      for(int x=0; x<rowCount; x++) {
        pinMode(rows[x], INPUT);
    }
 
    for (int x=0; x<colCount; x++) {
        pinMode(cols[x], INPUT_PULLUP);
    }
      digitalWrite(4, HIGH);
    }
    delay(1000);
}
