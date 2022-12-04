#include<TimerOne.h>
#include<MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(48,49,50,51,52,53); 

volatile int state = HIGH;
volatile int count = 0;
volatile int countR = 0;
const byte interruptPin = 2;

int LED = 22;
int trig = 26;
int echo = 27;
int sw = 2;
int LED_state = HIGH;


void setup() {
  lcd.begin(16,2);
  pinMode(sw,INPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  pinMode(LED,OUTPUT);
  MsTimer2::set(1000,timer0);
  MsTimer2::start();
  attachInterrupt(digitalPinToInterrupt(interruptPin),cnt,FALLING);
 if(count == 5){
  lcd.clear();
 }
}

void cnt(){
  count++;
}


void loop() {
  long unsigned secound = millis();
  float duration, distance;
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);
  distance = ((float)(340*duration)/10000)/2;
  
   if(count == 5){
    if(distance >= 20){
    digitalWrite(LED,HIGH);
    lcd.setCursor(0,1);
    lcd.print("Warining!!");
    delay(2000);
    lcd.setCursor(0,1);
    lcd.print("                ");
    delay(2000);
  }
 

}
}

void timer0(){
  
  
  float duration, distance;
  digitalWrite(trig,HIGH);
  delay(10);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);
  distance = ((float)(340*duration)/10000)/2;
  


if(count == 1 || count == 2){
  long unsigned secound = millis();
    lcd.setCursor(0,0);
    lcd.print("distance");
    lcd.setCursor(9,0);
    lcd.print(distance);
    lcd.setCursor(0,1);
    lcd.print(secound/1000);
     digitalWrite(LED,LED_state);
     LED_state =! LED_state;
}

if(count == 3 || count == 4){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("distance");
    lcd.setCursor(9,0);
    lcd.print(distance);
    
  if(distance <= 20){
    digitalWrite(LED,HIGH);
  }
  if(distance >= 20){
    digitalWrite(LED,LED_state);
  }
  LED_state =! LED_state;
}
if(count == 5){
    
    lcd.setCursor(0,0);
    lcd.print("distance");
    lcd.setCursor(9,0);
    lcd.print(distance);
  
  if(distance <= 20){

    digitalWrite(LED,LED_state);
  }
  LED_state =! LED_state;
}

}
