// Keyboard Matrix Tutorial Example
// baldengineer.com
// CC BY-SA 4.0
const int LED_1 = 12;   
const int LED_2 = 14;       
const int LED_3 = 16;
// JP1 is an input
byte rows[] = {3,1};
const int rowCount = sizeof(rows)/sizeof(rows[0]);
 
byte cols[] = {5,4,13};
const int colCount = sizeof(cols)/sizeof(cols[0]);
byte keys[colCount][rowCount];
 
void setup() {
 
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
 
void loop() {
    readMatrix();
    if(keys[2][0] == 0){

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, INPUT);      

  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);

  delay(3000);

  pinMode(LED_1, INPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, INPUT);      

      for(int x=0; x<rowCount; x++) {
        pinMode(rows[x], INPUT);
    }
 
    for (int x=0; x<colCount; x++) {
        pinMode(cols[x], INPUT_PULLUP);
    }
    }
    delay(1000);
}
