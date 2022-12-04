#include <LiquidCrystal.h>
LiquidCrystal lcd(48,49,50,51,52,53); 

volatile int count1 = 0;
volatile int count2 = 0;
const byte interruptPin1 = 2;
const byte interruptPin2 = 3;

String sw1line1 = "Falling Edge";

String sw2line1 = "Rising Edge";


void setup() {
  lcd.begin(16,2);
  noInterrupts();
  DDRA = 0x00;
  interrupts();
  attachInterrupt(digitalPinToInterrupt(interruptPin1),cnt1,FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2),cnt2,RISING);
}


void loop() {
  if(digitalRead(2)==HIGH){
    sw1();
  }

  if(digitalRead(3)==HIGH){
  sw2();
  }
}

void sw1(){
  lcd.setCursor(0,0);
    lcd.print(sw1line1);
    lcd.setCursor(0,1);
    lcd.print(count1);
  if(count1==1){
    PORTA = 0x01;
  }
  if(count1==2){
    PORTA = 0x03;
  }
  if(count1==3){
    PORTA = 0x07;
  }
  if(count1==4){
    PORTA = 0x0f;
  } 
   if(count1==5){
   PORTA = 0x1f;
  }
  if(count1==6){
    PORTA = 0x3f;
  }
  if(count1==7){
    PORTA = 0x7f;
  }
  if(count1==8){  
    PORTA = 0xff;
  }
  if(count1>8){
    PORTA = 0x00;
    count1=0;
  }
}

void sw2(){
    lcd.setCursor(0,0);
    lcd.print(sw2line1);
    lcd.setCursor(0,1);
    lcd.print(count2);
  if(count2==1){
    PORTA = 0xff;
  }
  if(count2==2){
    PORTA = 0x7f;
  }
  if(count2==3){
    PORTA = 0x07;
  }
  if(count2==4){
    PORTA = 0x3f;
  } 
  if(count2==5){
   PORTA = 0x0f;
  }
  if(count2==6){
    PORTA = 0x07;
  }
  if(count2==7){
    PORTA = 0x03;
  }
  if(count2==8){  
    PORTA = 0x01;
  }
  if(count2>8){
    PORTA = 0x00;
    count2=0;
  }
}

void cnt1(){
  count1++;
}

void cnt2(){
  count2++;
}
