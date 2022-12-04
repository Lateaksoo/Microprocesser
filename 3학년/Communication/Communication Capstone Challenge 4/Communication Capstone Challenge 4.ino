#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <string.h>

/*
lcd 관련
*/
#define LCD_WIDTH 16
#define LCD_HEIGHT 2
#define LCD_ADDRESS 0x27
LiquidCrystal_I2C lcd_I2C(LCD_ADDRESS, LCD_WIDTH, LCD_HEIGHT);

/*
문장 정의
*/
String SerialInputLine = "";
String OutputLine;
String Good_Mecha = "Good Mecha!!";
String Induk_University = "Induk University";
String NullLine = "                 ";

/* 
문장 길이
*/
int Induk_University_length;
int Good_Mecha_length;

/*
문장 좌우 이동 변수
*/
int LeftFrom = 16;
int LeftTo = 32;
int RightFrom = 17;
int RightTo = 33;


void setup() {
  Serial.begin(9600);
  lcd_I2C.init();
  lcd_I2C.backlight();
}

void ShiftLeft() {
  String Induk_University_Plus = NullLine + Induk_University + NullLine;
  Induk_University_length = Induk_University_Plus.length();
  for (int i = 0; i < Induk_University_length; i++) {
    delay(500);
    LeftFrom++;
    LeftTo++;
    lcd_I2C.setCursor(0, 1);
    OutputLine = Induk_University_Plus.substring(LeftFrom, LeftTo);
    lcd_I2C.print(OutputLine);
    if (LeftFrom > 34) {
      Serial.print("OVER");
      break;
    }
  }
}

void ShiftRight() {
  String Good_Mecha_Plus = NullLine + Good_Mecha + NullLine;
  Good_Mecha_length = Good_Mecha_Plus.length();
  for (int i = Good_Mecha_length; i > 0; i--) {
    OutputLine = Good_Mecha_Plus.substring(RightFrom, RightTo);
    lcd_I2C.print(OutputLine);
    delay(1000);
    RightFrom--;  //0
    RightTo--;    //16
    lcd_I2C.setCursor(0, 0);
    if (RightFrom < 0) {
      Serial.print("OVER");
      break;
    }
  }
}

void SerialRead() {
  if (Serial.available()) {
    char ReadSerial = Serial.read();
    SerialInputLine += ReadSerial;
  }
}

void InPutLineReset() {
  SerialInputLine = "";
}

void loop() {
  SerialRead();  //시리얼 통신으로 문장 입력받기
  if (SerialInputLine == Induk_University) {
    ShiftLeft();       //문장 좌로 움직이기
    InPutLineReset();  //시리얼 입력 초기화
  } else if (SerialInputLine == Good_Mecha) {
    ShiftRight();
    InPutLineReset();
  }
}