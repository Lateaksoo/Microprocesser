

#include<Servo.h>
Servo myservo; // 서보모터 변수지정

 
int LED = 5; // led 5번

int button1 = 3; // 버튼1 3번
int tiltbutton2 = 2; // 틸트센서 대신해서 버튼2 2번

void setup() {
  Serial.begin(9600);
   myservo.attach(9);// 서보모터 9번 연결
  pinMode(LED,OUTPUT); // led 출력
  pinMode(button1,INPUT);// 버튼1 입력
  pinMode(tiltbutton2,INPUT);// 틸트센서 대신해서 버튼2 입력 
 
}
void loop() {
   
 if(digitalRead(tiltbutton2)==LOW)//tilt sensor off
  { 
    
    for(int i=0; i<=180; i++){
      if(digitalRead(button1)==HIGH){
        break;
      }
      
      Serial.println("180 Angle Control");
      myservo.write(i);
      
    }
  }
 

  if(digitalRead(tiltbutton2)==HIGH)//tilt sensor off
  { 
   
    for(int i=0; i<=90; i++){
      if(digitalRead(button1)==HIGH){
        break;
      }
      Serial.println("90 Angle Control");
      myservo.write(i);
    }
  }
  if(digitalRead(button1)==HIGH){
    digitalWrite(LED,HIGH);
        delay(1000);
        digitalWrite(LED,LOW);
        delay(1000);
        digitalWrite(LED,HIGH);
        delay(1000);
        digitalWrite(LED,LOW);
        delay(1000);
        digitalWrite(LED,HIGH);
        delay(1000);
        digitalWrite(LED,LOW);
        delay(1000);
        
  myservo.detach();
}
   
}
