#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
byte smile1[8]={B00000, B00001, B00011, B00110, 
                  B00100, B00000, B00000, B00000,};
                  
byte smile2[8]={B00000, B10000, B11000, B01100, 
                  B00100, B00000, B00000, B00000,};   
                  
byte leftmouth1[8]={B00000, B00000, B00000, B00000, 
                  B11000, B01110, B00011, B00000,};   
byte leftmouth2[8]={B00000, B00000, B00000, B00000, 
                  B00000, B00000, B11000, B01111,};  
byte rightmouth1[8]={B00000, B00000, B00000, B00000, 
                  B00011, B01110, B11000, B00000,};   
byte rightmouth2[8]={B00000, B00000, B00000, B00000, 
                  B00000, B00000, B00011, B11110,};   

byte closeeye1[8]={B00000, B00000, B00000, B00111, 
                  B00111, B00000, B00000, B00000,};
byte closeeye2[8]={B00000, B00000, B00000, B11100, 
                  B11100, B00000, B00000, B00000,};                 
                                                                        
void setup() {
  // put your setup code here, to run once:
lcd.begin(16, 2);
}
void smile(){
  lcd.createChar(1,smile1);
  lcd.createChar(2,smile2);
  lcd.createChar(3,leftmouth1);
  lcd.createChar(4,leftmouth2);
  lcd.createChar(5,rightmouth1);
  lcd.createChar(6,rightmouth2);
  lcd.setCursor(5,0);
  lcd.write(1);
  lcd.setCursor(6,0);
  lcd.write(2);
  lcd.setCursor(9,0);
  lcd.write(1);
  lcd.setCursor(10,0);
  lcd.write(2);
  lcd.setCursor(6,2);
  lcd.write(3);
  lcd.setCursor(7,2);
  lcd.write(4);
  lcd.setCursor(8,2);
  lcd.write(6);
  lcd.setCursor(9,2);
  lcd.write(5);
}
void closeeye(){
  lcd.createChar(1,closeeye1);
  lcd.createChar(2,closeeye2);
  lcd.createChar(3,leftmouth1);
  lcd.createChar(4,leftmouth2);
  lcd.createChar(5,rightmouth1);
  lcd.createChar(6,rightmouth2);
  lcd.setCursor(5,0);
  lcd.write(1);
  lcd.setCursor(6,0);
  lcd.write(2);
  lcd.setCursor(9,0);
  lcd.write(1);
  lcd.setCursor(10,0);
  lcd.write(2);
  lcd.setCursor(6,2);
  lcd.write(3);
  lcd.setCursor(7,2);
  lcd.write(4);
  lcd.setCursor(8,2);
  lcd.write(6);
  lcd.setCursor(9,2);
  lcd.write(5);
}
void loop() {
  smile();
  delay(1000);
  closeeye();
  delay(1000);
  
}
