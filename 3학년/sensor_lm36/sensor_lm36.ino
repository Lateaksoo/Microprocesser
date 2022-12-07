#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h>
#define DHT11_PIN 6
dht DHT;

LiquidCrystal_I2C lcd(0x3F, 16, 2);

int ENA = 10; //모터 
int INA1 = 9;
int INA2 = 8;
int cmd = 0;

int reading;
float voltage;
float temperature;
float DHTtemp;
float temp;

int pan=7;
int lm35 = A0;  //Analog 0 번에 센서핀 연결

void setup() {
  Serial.begin(9600);  //PC와의 시리얼 통신 속도 설정
  lcd.init();
  lcd.backlight();
  pinMode(pan,OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(INA1, OUTPUT);
  pinMode(INA2, OUTPUT);
}

void loop() {
  getTemperature();
  DHTSensor();
  lcdDisplay();
  SerialPrint();
  PanActive();
}
void DHTSensor(){
  DHT.read11(DHT11_PIN);
  DHTtemp = DHT.temperature;
  temp =DHTtemp-3;
  
}
void SerialPrint() {  //시리얼 모니터에 온도랑 전압값 출력
  // Serial.print(temp);
  // Serial.println(" DHT temperature");
  Serial.println(reading);
  // Serial.print(temperature);
  // Serial.println(" lm36 temperature");
}

void lcdDisplay() { //lcd에 온도 출력 
  lcd.setCursor(0, 0);
  lcd.print("DHT : ");
  lcd.setCursor(6,0);
  lcd.print(temp);
  lcd.setCursor(0, 1);
  lcd.print("lm36 : ");
  lcd.setCursor(7,1);
  lcd.print(temperature);
}

void getTemperature() { //lm36센서로부터 전압값 측정 온도로 변환  
  //전압의 변화값을 센서핀으로 부터 읽음
  reading = analogRead(lm35);
  //전압값을 읽음, 센서에 공급되는 전압이 5V면 읽은값x5.0 이고 3.3V 이면 3.3을 곱해준다
  voltage = (reading * 5.0) / 1024;
  //전압값(mV)으로 온도 구함 (섭씨) , 시리얼 모니터 출력
  temperature = (voltage - 0.5) * 100;
    //0.5초 간격으로 측정
}

void PanActive(){
 if(temperature > 30 && temp >30){
   digitalWrite(pan,HIGH);
   motor();
 }
 else{
   digitalWrite(pan,LOW);
 }
}

void motor(){
  
  
  Serial.println("Forward-PWM");
  
  digitalWrite(INA1, HIGH);
  digitalWrite(INA2, LOW);
 

}