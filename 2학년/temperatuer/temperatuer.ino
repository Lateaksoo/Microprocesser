#include <DHT.h>


#define DHT_PIN A2 // 온습도센서 아날로그 2번핀연결
DHT dht(DHT_PIN, DHT11);



void setup() {
Serial.begin(9600);
Serial.println("DHT Test ~!!");
dht.begin();  
}

void loop() {
  boolean chk = dht.read();
  
  if(chk)
  {
    Serial.print("Humidity (%): ");
    Serial.println((int)dht.readHumidity());
    Serial.print("Temperature (℃): ");
    Serial.println((int)dht.readTemperature(false));
  }else{
    Serial.print("Failed to read info.");
  }
delay(1000);
}
