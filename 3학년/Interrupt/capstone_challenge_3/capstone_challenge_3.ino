volatile int count =0;
const byte interruptPin = 2;
#include <LiquidCrystal.h>
LiquidCrystal lcd(48,49,50,51,52,53); 

void setup() {
  lcd.begin(16,2);
  noInterrupts();
  DDRA = 0xff;
  interrupts();
  attachInterrupt(digitalPinToInterrupt(interruptPin),cnt,FALLING);
  
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print(count);
  if(count<=5){
    PORTA = 0xff;
  }
  if(count>5){
    PORTA = 0x00;
  }
  if(count==11){
    count=0;
  }
}

void cnt(){
  count++;
}
