//slave
#include <Wire.h>
#include <LiquidCrystal.h>
#define slave 20

const int LED = 'l';
const int HI = 'h';
const int BYE = 'b';

bool state = false;
byte rec[128];

LiquidCrystal lcd(32, 33, 34, 35, 36, 37);

void setup() {
  Wire.begin(slave);
  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(28, OUTPUT);
}

void record(int receiveNum) {
  for (int i = 0; i < receiveNum; i++) {
    rec[i] = Wire.read();
  }
}

void loop() {
  Wire.onReceive(record);
  char recivedNum = rec[0];
  switch (recivedNum) {  //저장된 통신용 상수가
    case LED:
      digitalWrite(28, state);
      state = !state;
      rec[0] = ",";
      break;
    case HI:
      LcdClear();
      lcd.setCursor(0, 0);
      lcd.print("HI");
      rec[0] = ",";
      break;
    case BYE:
      LcdClear();
      lcd.setCursor(0, 0);
      lcd.print("BYE");
      rec[0] = ",";
      break;
  }
}

void LcdClear() {
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
}
