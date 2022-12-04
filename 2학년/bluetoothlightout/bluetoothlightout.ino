#include<SoftwareSerial.h>
#include<Servo.h>
Servo myservo1;
Servo myservo2;


int bTx = 2;
int bRx = 3;

SoftwareSerial bt(bTx, bRx);

void setup() {
Serial.begin(9600);
delay(100);
bt.begin(9600);

myservo1.attach(9);
myservo2.attach(10);
}

void loop() {
  char value;
  if(bt.available()){
    value=(char)bt.read(); 
  }
  if(value == '1')
  {
    myservo1.write(0);
    myservo2.write(30);
  }
  if(value == '2')
  {
    myservo1.write(30);
    myservo2.write(0);
  }
}
