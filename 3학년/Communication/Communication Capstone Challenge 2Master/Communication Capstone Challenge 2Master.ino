//Mater
#include <Wire.h>
#include <string.h>
#include <stdio.h>

#define SLAVE 20  // 통신용 슬레이브

const int LED = 'l';
const int HI = 'h';
const int BYE = 'b';

void setup() {
  Wire.begin();
  Serial.begin(9600);

}

void loop() {
  if(Serial.available()>0){
char Data = Serial.read();
transferData(Data);
Serial.println(Data);
  }

}

void transferData(char data) {
  Wire.beginTransmission(SLAVE);  // data 전송 시작
  Wire.write(data);               // buffer에 data 저장
  Wire.endTransmission();         // buffer에 저장된 data 전송
}