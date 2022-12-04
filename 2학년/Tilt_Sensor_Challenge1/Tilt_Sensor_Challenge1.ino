void setup() {
  pinMode(7, INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  if(digitalRead(7)==LOW)
  {
    Serial.println("on");
    digitalWrite(13,HIGH);
  }
  else
  {Serial.println("off");
  digitalWrite(13,LOW);
  }
  delay(1000);
}
