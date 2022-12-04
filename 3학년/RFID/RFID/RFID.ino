#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#include <deprecated.h>
#include <MFRC522.h>
#include <MFRC522Extended.h>
#include <require_cpp11.h>

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 29
#define SS_PIN 30

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  ShowReaderDetails();
  Serial.println("Scan PICC to see UID, type, and data   blaocks");
}

void loop() {
  if(!mfrc522.PICC_IsNewCardPresent()){
    return;
  }
  if(!mfrc522.PICC_ReadCardSerial()){
    return;
  }
  mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
}

void ShowReaderDetails(){
  byte v =mfrc522.PCD_ReadRegister(mfrc522.VersionReg);
  Serial.print("MFRC522 Software Version : 0x");
  Serial.print(v,HEX);
  if(v == 0x91) Serial.print(" = v1.0");
  else if( v== 0x92) Serial.print(" = v2.0");
  else Serial.print("(unknown)");
  Serial.println("");
  if((v==0x00)||(v==0xFF)){
    Serial.println("WARNING : Coummunication failure, is the MFRC522 properly connercted?");
  }
}
