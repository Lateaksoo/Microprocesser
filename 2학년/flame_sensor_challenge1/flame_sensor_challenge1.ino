#define flame A0
int state = 0;
void setup() {
  Serial.begin(9600);
  pinMode(flame,INPUT);
  pinMode(10,OUTPUT);
}

void loop() {
  state = digitalRead(flame);
  if(state == 0){
    digitalWrite(10,HIGH);
    int flamesensor = analogRead(flame);
    Serial.print("Flame Sensor Value");
    Serial.println(flamesensor);
    delay(1000);
  }
else{
  digitalWrite(10,LOW);
   int flamesensor = analogRead(flame);
   Serial.print("Flame Sensor Value");
    Serial.println(flamesensor);
    delay(1000);
}
}
