#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 53
#define RST_PIN 5
 
MFRC522 mfrc(SS_PIN, RST_PIN);
 
int segment[7]={36,37,38,39,40,41,42};
int digitForNum[10][7] = {
  {1,1,1,1,1,1,0},//0
  {0,1,1,0,0,0,0},//1
  {1,1,0,1,1,0,1},//2
  {1,1,1,1,0,0,1},//3
  {0,1,1,0,0,1,1},//4
  {1,0,1,1,0,1,1},//5
  {1,0,1,1,1,1,1},//6
  {1,1,1,0,0,0,0},//7
  {1,1,1,1,1,1,1},//8
  {1,1,1,1,0,1,1} //9
};
byte nuidPICC[4];
byte CardOne[4] = {115,202,136,12};
byte CardTwo[4] = {19,241,90,2};
byte TagOne[4] = {108,217,106,34};
byte TagTwo[4] = {172,130,113,34};
 
void setup() {
  for(int i=0;i<7;i++){
    pinMode(segment[i],OUTPUT);
  }
  Serial.begin(230400);
  SPI.begin();
  mfrc.PCD_Init();
  Serial.println("PICC를 Scan하면 제품 코드가 나옵니다.");
}
 
void loop() {
  if(!mfrc.PICC_IsNewCardPresent()) return;  // 카드 읽으면 true 인데 !붙어서 false니까 if문 거치지 말고 넘어가 
  if(!mfrc.PICC_ReadCardSerial()) return;
 
  if (mfrc.uid.uidByte[0] == CardOne[0] &&  //현재 카드가 첫번째 카드인지 인식 
    mfrc.uid.uidByte[1] == CardOne[1] && 
    mfrc.uid.uidByte[2] == CardOne[2] && 
    mfrc.uid.uidByte[3] == CardOne[3] ) {
      Serial.println(F("CARD ONE detected!!"));
      printDec(mfrc.uid.uidByte, mfrc.uid.size);
    Serial.println();
 
  for(int i=0;i<7;i++){
  digitalWrite(segment[i],digitForNum[1][i]);
    }
  
    }
    
  if (mfrc.uid.uidByte[0] == CardTwo[0] &&  //현재 카드가 두번째 카드인지 인식 
    mfrc.uid.uidByte[1] == CardTwo[1] && 
    mfrc.uid.uidByte[2] == CardTwo[2] && 
    mfrc.uid.uidByte[3] == CardTwo[3] ) {
      Serial.println(F("CARD Two detected!!"));
      printDec(mfrc.uid.uidByte, mfrc.uid.size);
    Serial.println();
    for(int i=0;i<7;i++){
  digitalWrite(segment[i],digitForNum[3][i]);
    }
    }
    
   if (mfrc.uid.uidByte[0] == TagOne[0] &&  //현재 카드가 첫번째 태그인지 인식 
    mfrc.uid.uidByte[1] == TagOne[1] && 
    mfrc.uid.uidByte[2] == TagOne[2] && 
    mfrc.uid.uidByte[3] == TagOne[3] ) {
      Serial.println(F("Tag ONE detected!!"));
      printDec(mfrc.uid.uidByte, mfrc.uid.size);
    Serial.println();
    for(int i=0;i<7;i++){
  digitalWrite(segment[i],digitForNum[2][i]);
    }
    }
    
   if (mfrc.uid.uidByte[0] == TagTwo[0] &&  //현재 카드가 두번째 태그인지 인식 
    mfrc.uid.uidByte[1] == TagTwo[1] && 
    mfrc.uid.uidByte[2] == TagTwo[2] && 
    mfrc.uid.uidByte[3] == TagTwo[3] ) {
      Serial.println(F("Tag Two detected!!"));
      printDec(mfrc.uid.uidByte, mfrc.uid.size);
    Serial.println();
    for(int i=0;i<7;i++){
  digitalWrite(segment[i],digitForNum[4][i]);
    }
    } 
 
  mfrc.PICC_HaltA();
  mfrc.PCD_StopCrypto1();
}
 
void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}
