#include <LiquidCrystal.h>
LiquidCrystal lcd(22,23,24,25,26,27); 

int IN1 = 36;
int IN2 = 38;
int IN3 = 40;
int IN4 = 42;

int echo = 33;
int trig = 32;

int Steps = 0;
int steps_left;

boolean Direction = true;
unsigned long last_time;
unsigned long currentMillis;
long time;
float duration, distance;

void setup() {
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
}

void Half_degree(){
  int half = 4095/2;
  while(half>0){
    currentMillis = micros();
    if(currentMillis-last_time>=1000)
    {
      stepper(1);
      time=time+micros()-last_time;
      last_time=micros();
      if(distance >10){
      break;
    }
      half--;
    }
  }
  Direction=!Direction;
  half=4095/2;
}

void Forward(){
  Direction = 1;
  int forward = 4095;
  while(forward>0){
    currentMillis = micros();
    if(currentMillis-last_time>=1000)
    {
      stepper(1);
      time=time+micros()-last_time;
      last_time=micros();
      if(distance <=10 || distance >=30){
        break;
      }
      forward--;
    }
  }
  forward=4095;
}

void Reverse(){
  Direction = 0;
  int reverse = 4095;
  while(reverse>0){
    currentMillis = micros();
    if(currentMillis-last_time>=1000)
    {
      stepper(1);
      time=time+micros()-last_time;
      last_time=micros();
      if(distance<30){
        break;
      }
      reverse--;
    }
  }
  reverse=4095;
}

void stepper(int xw){
  for(int x=0;x<xw;x++){
    switch(Steps){
      case 0: runStep(LOW,LOW,LOW,HIGH); break;
      case 1: runStep(LOW,LOW,HIGH,HIGH); break;
      case 2: runStep(LOW,LOW,HIGH,LOW); break;
      case 3: runStep(LOW,HIGH,HIGH,LOW); break;
      case 4: runStep(LOW,HIGH,LOW,LOW); break;
      case 5: runStep(HIGH,HIGH,LOW,LOW); break;
      case 6: runStep(HIGH,LOW,LOW,LOW); break;
      case 7: runStep(HIGH,LOW,LOW,HIGH); break;
      default : runStep(LOW,LOW,LOW,LOW);break;
    }
    SetDirection();
  }
}

void runStep(int value1, int value2, int value3, int value4)
{
  digitalWrite(IN1, value1);
  digitalWrite(IN2, value2);
  digitalWrite(IN3, value3);
  digitalWrite(IN4, value4);
}

void SetDirection()
{
  if(Direction==1) {Steps++;}
  if(Direction==0) {Steps--;}
  if(Steps>7) {Steps=0;}
  if(Steps<0) {Steps=7;}
}

void loop() {
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);
  
  duration = pulseIn(echo,HIGH);
  distance = ((float)(340*duration)/10000)/2;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(distance);
    
  if(distance <= 10){

    lcd.setCursor(0,1);
    lcd.print("round trip");
    Half_degree();
  }
  else if(distance >10 && distance<30){

    lcd.setCursor(0,1);
    lcd.print("Forward");
    Forward();
  }
  else if(distance>=30){

    lcd.setCursor(0,1);
    lcd.print("Reverse");
    Reverse();
  }
}
