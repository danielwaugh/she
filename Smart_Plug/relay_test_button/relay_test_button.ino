int flag = 0;

void setup() {
  pinMode(13, INPUT_PULLUP);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
}

void loop() {
  if(digitalRead(13) == 0)
  {
    if(flag == 0)
    {
      flag = 1;
      digitalWrite(12, HIGH);
      delay(500);
    }
    else if(flag == 1)
    {
      flag = 0;
      digitalWrite(12, LOW);
      delay(500);
    }
  }
}
