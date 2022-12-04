 #include <DHT.h>

#define DHT_PIN A2 // 온습도센서 아날로그 2번핀연결
DHT dht(DHT_PIN, DHT11);

#include<Servo.h>
Servo myservo; // 서보모터 변수지정

int tilt = 8; //틸트센서 10번 
int led = 5; // led 5번
int buzzer = 4; // 부저 4번
int button = 3; // 버튼 3번

void setup() {
  Serial.begin(9600);
  myservo.attach(11); // 서보모터 11번 연결
  pinMode(tilt,INPUT); //틸트 입력  
  pinMode(led,OUTPUT); // led 출력
  pinMode(buzzer,OUTPUT); // 부저 출력
  pinMode(button,INPUT); // 버튼 입력 
  dht.begin(); //온습도센서 동작 시작
}

void loop(){
  boolean chk = dht.read();
    Serial.print("Humidity (%): ");
    Serial.println((int)dht.readHumidity());
    Serial.print("Temperature (℃): ");
    Serial.println((int)dht.readTemperature(false));
  delay(1000);
  int t = dht.readTemperature(); // t는 온도
  int h = dht.readHumidity(); //h는 습도
  
 if(h>=90){
  digitalWrite(led,HIGH);
  myservo.write(90);
 }
 if(t<19){
  myservo.write(60);
  
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
  delay(1000);
 }
if(digitalRead(button) == HIGH){
      myservo.write(180);
      digitalWrite(led,HIGH);
      digitalWrite(buzzer,HIGH);
      }
      if(digitalRead(button) == LOW && h<90){
      digitalWrite(led,LOW);
      digitalWrite(buzzer,LOW);
      myservo.write(0);
      }
if(digitalRead(button) == LOW){
  digitalWrite(buzzer,LOW);
}
if(digitalRead(tilt)==HIGH){
  myservo.write(30);
  digitalWrite(led,LOW);
  digitalWrite(buzzer,HIGH);
}
  


}
