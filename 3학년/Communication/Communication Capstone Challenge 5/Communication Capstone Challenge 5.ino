
#include <LiquidCrystal.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd_I2C(0x27, 16, 2);
LiquidCrystal lcd(22, 23, 24, 25, 26, 27);
String OutputLine = "";
String Induk_University = "Induk University";
String Good_Mecha = "Good Mecha!!";


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd_I2C.begin();
}

void loop() {
  if (Serial.available()) {
    char ReadSerial = Serial.read();
    OutputLine += ReadSerial;
  }

  // Serial.println(OutputLine);

  if (OutputLine == Induk_University) {
    lcd.setCursor(0, 0);
    lcd.print(Induk_University);
    Serial.print(Induk_University);
    OutputLine = "";
  } 
  if (OutputLine == Good_Mecha) {
    lcd_I2C.setCursor(0, 0);
    lcd_I2C.print(Good_Mecha);
    Serial.print(Good_Mecha);
    OutputLine = "";
  }
}