#include<TimerOne.h>

void setup()
{
  pinMode(22,OUTPUT);
  pinMode(23,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(2,INPUT);

  Timer1.initialize(2000000);
  Timer1.attachInterrupt( timerIsr );
}

void loop()
{
  if(digitalRead(2)==HIGH){
    digitalWrite(28,HIGH);
  }
  else
  {
    digitalWrite(28,LOW);
  }
}

void timerIsr()
{
  
  digitalWrite(22,digitalRead(22)^1);
  if(digitalRead(22)==LOW){
    digitalWrite(23,HIGH);
  }
  else{
    digitalWrite(23,LOW);
  }
  
}
