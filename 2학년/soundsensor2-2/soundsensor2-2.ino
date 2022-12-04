#include <LiquidCrystal.h>
LiquidCrystal lcd(22,23,24,25,26,27); 

int led1 = 28;
int led2 = 29;
int sensor= A2;
int buzzer =30;
int count =0;

String led1on="Light 1 On";
String led2on="Light 2 On";
String buzzeron="Sound On";

unsigned long firstTime=0;
unsigned long lastTime=0;
boolean start=true;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(sensor,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(buzzer,OUTPUT);

}


void loop() {
  lastTime=millis();
   int Sound = analogRead(sensor);
  
   Serial.println(Sound);
 
   if(digitalRead(sensor) == HIGH){ // 소리가 감지되면
     if(start){ 
      firstTime=millis();
    }
    count++;
    start=false;
    delay(50);
  }  
  int delayTime=lastTime-firstTime; 
    if(delayTime>2000){                 //시간이 지났는데도 박수소리가 안난다면  박수 소리에 맞는 led 점등 후 리셋 
        
        //꺼지는부분
   if((count==1)&&(digitalRead(led1)==HIGH)){
    digitalWrite(led1,LOW);
    lcd.clear();
    count=0;
   }
   if((count==2)&&(digitalRead(led2)==HIGH)){
    digitalWrite(led2,LOW);
    lcd.clear();
    count=0;
   }
   if((count==3)&&(digitalRead(buzzer)==HIGH)){
    digitalWrite(buzzer,LOW);
    lcd.clear();
    count=0;
   }

 //켜지는 부분  
 if(count==3){//buzzer on
  lcd.clear();
   digitalWrite(led1,LOW);
   digitalWrite(led2,LOW);
   digitalWrite(buzzer,HIGH);
   
   lcd.setCursor(0,0);
   lcd.print(buzzeron);
   lcd.setCursor(0,1);
   lcd.print(count);

   count=0;
 }
 if(count==2){ //led 2 on
  lcd.clear();
   digitalWrite(led1,LOW);
   digitalWrite(led2,HIGH);
   digitalWrite(buzzer,LOW);
   
   lcd.setCursor(0,0);
   lcd.print(led2on);
   lcd.setCursor(0,1);
   lcd.print(count);

   count=0;
 }
 if(count==1){ //led 1 on
  lcd.clear();
   digitalWrite(led1,HIGH);
   digitalWrite(led2,LOW);
   digitalWrite(buzzer,LOW);
   
   lcd.setCursor(0,0);
   lcd.print(led1on);
   lcd.setCursor(0,1);
   lcd.print(count);

   count=0;
 }
             
     count=0;
     start=true;
 }

  
 
}
