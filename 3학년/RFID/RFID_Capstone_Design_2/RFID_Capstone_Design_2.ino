#include <SPI.h>
#include <MFRC522.h>
#include <LiquidCrystal.h>
 
LiquidCrystal lcd(30,31,32,33,34,35);
String CardOneString = "Banana";
String CardTwoString = "Orange";
String TagOneString = "Apple";
String TagTwoString = "Mango";
 
#define SS_PIN 53
#define RST_PIN 5
 
MFRC522 mfrc(SS_PIN, RST_PIN);

 
 
byte nuidPICC[4];
byte CardOne[4] = {115,202,136,12};
byte CardTwo[4] = {19,241,90,2};
byte TagOne[4] = {108,217,106,34};
byte TagTwo[4] = {172,130,113,34};
 
void setup() {
  Serial.begin(9600);
  mfrc.PCD_Init();
  SPI.begin();
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.clear();
  Serial.println("PICC를 Scan하면 제품명이 나옵니다.");
}
 
void loop() {
  lcd.setCursor(0,0);
  lcd.print("s");
  if(!mfrc.PICC_IsNewCardPresent()) return;  // 카드 읽으면 true 인데 !붙어서 false니까 if문 거치지 말고 넘어가 
  if(!mfrc.PICC_ReadCardSerial()) return;

  for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = mfrc.uid.uidByte[i];
    }
  if(mfrc.uid.uidByte[0] == CardOne[0] &&  //현재 카드가 첫번째 카드인지 인식 
     mfrc.uid.uidByte[1] == CardOne[1] && 
     mfrc.uid.uidByte[2] == CardOne[2] && 
     mfrc.uid.uidByte[3] == CardOne[3] ) { //현재 카드가 첫번째 카드이면 
     Serial.println(F("Banana")); //시리얼 모니터에 바나나 표시 
     lcd.clear();  //lcd 초기화 
     lcd.setCursor(0,0); //lcd 0,0지정 
     lcd.print(CardOneString); // 첫번째 카드 문장 lcd에 출력 


    }
    
  if(mfrc.uid.uidByte[0] == CardTwo[0] &&  //현재 카드가 두번째 카드인지 인식 
     mfrc.uid.uidByte[1] == CardTwo[1] && 
     mfrc.uid.uidByte[2] == CardTwo[2] && 
     mfrc.uid.uidByte[3] == CardTwo[3] ) {
     Serial.println(F("Orange"));
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print(CardTwoString);

    }
    
  if(mfrc.uid.uidByte[0] == TagOne[0] &&  //현재 카드가 첫번째 태그인지 인식 
     mfrc.uid.uidByte[1] == TagOne[1] && 
     mfrc.uid.uidByte[2] == TagOne[2] && 
     mfrc.uid.uidByte[3] == TagOne[3] ) {
     Serial.println(F("Apple"));
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print(TagOneString);

    }
    
  if(mfrc.uid.uidByte[0] == TagTwo[0] &&  //현재 카드가 두번째 태그인지 인식 
     mfrc.uid.uidByte[1] == TagTwo[1] && 
     mfrc.uid.uidByte[2] == TagTwo[2] && 
     mfrc.uid.uidByte[3] == TagTwo[3] ) {
     Serial.println(F("Mango"));
     lcd.clear();
     lcd.setCursor(0,0);
     lcd.print(TagTwoString);

    } 

  

  mfrc.PICC_HaltA();
  mfrc.PCD_StopCrypto1();

}
