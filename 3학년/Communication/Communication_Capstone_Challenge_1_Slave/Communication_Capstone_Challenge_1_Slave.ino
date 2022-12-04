#include<Wire.h>
#define slave 0x04
byte count = 0;

void setup() {
  Wire.begin(slave);
  Wire.onRequest(sendToMaster);
}

void loop() {
}

void sendToMaster() {
  Wire.write(++count);
  if(count==50){
    count=0;
  }
}