#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 23, 24, 25, 26, 27);
String lcdString = "";



void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.setCursor(0, 0);
}

void loop() {


  if (Serial.available()) {

    delay(100);
    while (Serial.available() > 0) {       //문자 수 만큼 반복
      char lcdChar = (char)Serial.read();  //문자 하나씩 읽고
      lcdString += lcdChar;                //읽은 문자를 하나씩 더해 문자열을 만듬
    }
    lcd.print(lcdString);  //문자열 LCD에 출력
    Serial.println(lcdString);
    lcdString = "";  //문자열 초기화
    lcd.print("               ");
    lcd.setCursor(0, 1);
    lcd.print(lcdString);
  }
}
