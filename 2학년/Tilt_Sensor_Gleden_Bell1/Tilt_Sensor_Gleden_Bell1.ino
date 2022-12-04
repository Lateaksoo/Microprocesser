void setup() {
  pinMode(2, INPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(10,OUTPUT);          
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(2)==HIGH)
  {
    Serial.println("on");
    digitalWrite(9,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
     unsigned char j;
    for(j=9;j<=10;j++)
    digitalWrite(j,HIGH);
  }
  else
  {
    Serial.println("off");
  unsigned char k;
   digitalWrite(9,LOW);
   digitalWrite(3,LOW);
   digitalWrite(8,LOW);
   digitalWrite(7,LOW);
   digitalWrite(10,HIGH);
  for(k=4;k<=6;k++)
    digitalWrite(k,HIGH);
  }
  delay(1000);
}
