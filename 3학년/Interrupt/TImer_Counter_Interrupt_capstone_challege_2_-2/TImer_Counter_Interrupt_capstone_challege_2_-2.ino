#include<MsTimer2.h>

int buzzer = 28;
int LED1 = 22;
int LED2 = 23;
int sw = 2;
int LED1_state = HIGH;
int switch_state;

void setup() {
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sw,INPUT);
  MsTimer2::set(2000,timer0);
  MsTimer2::start();
}

void loop() {
  switch_state = digitalRead(2);
  if(switch_state == HIGH){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }
}
void timer0()
{
  if(LED1_state == HIGH){
    digitalWrite(LED1,LED1_state);
    digitalWrite(LED2,LOW);
}
if(LED1_state == LOW){
  digitalWrite(LED1,LED1_state);
  digitalWrite(LED2,HIGH);
}
 LED1_state =! LED1_state;
}
