#include <Wire.h>
#define slave 0x04
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


/*
i2c 통신 상수 
*/
const int Induk_University = '1';
const int Good_Mecha = '2';

/**
  통신 데이터 저장 배열
*/
byte rec[128];

void setup() {
  Wire.begin(slave);
  lcd.init();
  lcd.backlight();
}

void loop() {
  Wire.onReceive(record);
  char recivedNum = rec[0];

  switch (recivedNum) {
    case Induk_University:
      LcdClear();
      lcd.setCursor(0, 0);
      lcd.print("INDUK University");
      rec[0] = ',';
      break;
      case Good_Mecha :
      LcdClear();
      lcd.setCursor(0,0);
      lcd.print("Good Mecha!!!");
      rec[0] = ',';
      break;
  }
}

void LcdClear(){
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("                ");
}

void record(int receiveNum) {
  for (int i = 0; i < receiveNum; i++) {
    rec[i] = Wire.read(); // 마스터에서 슬레이브에게 요청한 data를 read 하는 함수로 한 Byte씩 read하고 rec[]배열에 저장 
  }
}