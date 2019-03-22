const int LED_1 = 12;   
const int LED_2 = 14;       
const int LED_3 = 16;

void setup() {
}

void loop() {

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, INPUT);      

  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);
  delay(500);

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, OUTPUT);      

  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_3, LOW);
 delay(500);

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, INPUT);      

  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_1, LOW);
 delay(500);

  pinMode(LED_1, INPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, OUTPUT);      

  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, LOW);
 delay(500);

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, OUTPUT);      

  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_1, LOW);
 delay(500);

  pinMode(LED_1, INPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, OUTPUT);      

  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_2, LOW);
 delay(500);

}
