const int LED_1 = 2;   
const int LED_2 = 3;       
const int LED_3 = 4;
const int LED_4 = 5; 

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, INPUT);      
  pinMode(LED_4, INPUT); 

  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);

  delay(1);

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, OUTPUT);      
  pinMode(LED_4, INPUT); 

  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_3, LOW);

  delay(1);

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, INPUT);      
  pinMode(LED_4, OUTPUT); 

  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_4, LOW);

  delay(1);

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, INPUT);      
  pinMode(LED_4, INPUT); 

  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_1, LOW);

  delay(1);

  pinMode(LED_1, INPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, OUTPUT);      
  pinMode(LED_4, INPUT); 

  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, LOW);

  delay(1);

  pinMode(LED_1, INPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, INPUT);      
  pinMode(LED_4, OUTPUT); 

  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_4, LOW);

  delay(1);

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, OUTPUT);      
  pinMode(LED_4, INPUT); 

  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_1, LOW);

  delay(1);

  pinMode(LED_1, INPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, OUTPUT);      
  pinMode(LED_4, INPUT); 

  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_2, LOW);

  delay(1);

  pinMode(LED_1, INPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, OUTPUT);      
  pinMode(LED_4, OUTPUT); 

  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_4, LOW);

  delay(1);

}
