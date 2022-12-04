//MASTER
#include <Wire.h>
#define slave 0x04

/*
i2c 통신 상수 
*/
const int Induk_University = '1';
const int Good_Mecha = '2';

void setup() {
  Wire.begin();
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    char ReadSerial = Serial.read();
    Serial.println(ReadSerial);
    if (ReadSerial == '1') {
      transferData(Induk_University);
      while (Serial.available() == 0) {
        Serial.println("1");
        delay(1000);
      }
    } else if (ReadSerial == '2') {
      transferData(Good_Mecha);
      while (Serial.available() == 0) {
        Serial.println("2");
        delay(1000);
      }
    }
  }
}

void transferData(char data) {
  Wire.beginTransmission(slave);  // data 전송 시작
  Wire.write(data);               // buffer에 data 저장
  Wire.endTransmission();         // buffer에 저장된 data 전송
}