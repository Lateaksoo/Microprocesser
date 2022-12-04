
#include <LiquidCrystal.h>
LiquidCrystal lcd(22,23,24,25,26,27); 
int led1 = 28;
int led2 = 29;
int sw1 = 30;
int sw2 = 31;


String sw1on="Switch 1 ON";
String sw1on2="Lamp 1 On";

String sw2on="Switch 2 ON";
String sw2on2="Lamp 2 On";

String next="Enter Next";

void setup() {
  lcd.begin(16,2);
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  
}

void loop() {
 
  
  if(digitalRead(sw1)==HIGH){
    digitalWrite(led1,HIGH);
    lcd.setCursor(0,0);
    lcd.print(sw1on);
    lcd.setCursor(0,1);
    lcd.print(sw1on2);
  }
  if(digitalRead(sw2)==HIGH){
    digitalWrite(led2,HIGH);
    lcd.setCursor(0,0);
    lcd.print(sw2on);
    lcd.setCursor(0,1);
    lcd.print(sw2on2);
  }
  if((digitalRead(led1)==HIGH)&&(digitalRead(led2)==HIGH)){
    lcd.setCursor(13,1);
    
    for(int i=0;i<10;i++){
      
    lcd.print(i++);
    
    }
    
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(next);
      while(1){
      for(int i=0;i<6;i++){
        lcd.scrollDisplayRight();
        delay(500);
      }
       for(int j=0;j<6;j++){
        lcd.scrollDisplayLeft();
        delay(500);
      }
      }
    }
    
}
