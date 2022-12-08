#include<SoftwareSerial.h>

int bTx = 2;
int bRx = 3;
int buzzer = 13;

SoftwareSerial bt(bTx, bRx);

void setup(){
  Serial.begin(9600);
  delay(100);
  bt.begin(9600);
  pinMode(buzzer,OUTPUT);
}

void loop(){
  char value;
  if(bt.available())
  {
    value =(char)bt.read();

    Serial.print("value = ");
    Serial.println(value);

    if(value == '1')
    {
      Serial.println("buzzer ON");
      digitalWrite(buzzer,HIGH);
    }
  if(value == '2')
  {
    Serial.println("buzzer OFF");
    digitalWrite(buzzer,LOW);
  }
  }
  
}
