#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte see[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b10001,
  0b11111
};
byte seedown[8] = { 0b11111, 0b10001, 0b10001,0b10001,0b11111,0b11111, 0b11111,0b11111
};
byte seeright[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b10111,
  0b10111,
  0b10111,
  0b10001,
  0b11111
};  
byte seeleft[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b11101,
  0b11101,
  0b11101,
  0b10001,
  0b11111
};            
byte seeup[8] = {
  0b11111,
  0b11111,
  0b11111,
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b11111
};  
byte smile1[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b10000,
  0b11000,
  0b01100,
  0b00111,
  0b00011
};  
byte smile[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111
};  
 byte smile2[8] = {
 0b00000,
  0b00000,
  0b00000,
  0b00001,
  0b00011,
  0b00110,
  0b11100,
  0b11000
};                                                                 
void setup() {
 
lcd.begin(16, 2);
}
void seefront(){
  lcd.createChar(1,see);
  lcd.createChar(2,smile1);
  lcd.createChar(3,smile);
  lcd.createChar(4,smile2);
  lcd.setCursor(5,0);
  lcd.write(1);
  lcd.setCursor(9,0);
  lcd.write(1);
  lcd.setCursor(5,1);
  lcd.write(2);
  lcd.setCursor(6,1);
  lcd.write(3);
  lcd.setCursor(7,1);
  lcd.write(3);
  lcd.setCursor(8,1);
  lcd.write(4);
}

void loop() {
  seefront();
  delay(1000);
  
  
}
