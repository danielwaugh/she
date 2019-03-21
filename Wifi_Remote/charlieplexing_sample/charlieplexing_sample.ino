const int LED_1 = 14;   
const int LED_2 = 12;       
const int LED_3 = 13;
const int LED_4 = 5; 

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(4, LOW);
}

void loop() {

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, INPUT);      
  pinMode(LED_4, INPUT); 

  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_2, LOW);
  delayMicroseconds(50);


  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, OUTPUT);      
  pinMode(LED_4, INPUT); 

  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_3, LOW);

  delayMicroseconds(50);

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, INPUT);      
  pinMode(LED_4, OUTPUT); 

  digitalWrite(LED_1, HIGH);
  digitalWrite(LED_4, LOW);

  delayMicroseconds(50);

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, INPUT);      
  pinMode(LED_4, INPUT); 

  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_1, LOW);

  delayMicroseconds(50);

  pinMode(LED_1, INPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, OUTPUT);      
  pinMode(LED_4, INPUT); 

  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_3, LOW);

  delayMicroseconds(50);

  pinMode(LED_1, INPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, INPUT);      
  pinMode(LED_4, OUTPUT); 

  digitalWrite(LED_2, HIGH);
  digitalWrite(LED_4, LOW);

  delayMicroseconds(50);

  pinMode(LED_1, OUTPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, OUTPUT);      
  pinMode(LED_4, INPUT); 

  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_1, LOW);

  delayMicroseconds(50);

  pinMode(LED_1, INPUT);    
  pinMode(LED_2, OUTPUT);     
  pinMode(LED_3, OUTPUT);      
  pinMode(LED_4, INPUT); 

  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_2, LOW); 

  delayMicroseconds(50);

  pinMode(LED_1, INPUT);    
  pinMode(LED_2, INPUT);     
  pinMode(LED_3, OUTPUT);      
  pinMode(LED_4, OUTPUT); 

  digitalWrite(LED_3, HIGH);
  digitalWrite(LED_4, LOW);

  delayMicroseconds(50);

}
