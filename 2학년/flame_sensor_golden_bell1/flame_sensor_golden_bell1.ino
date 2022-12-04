#define flame A0
int red = 12;
int green = 11;
int blue = 10;
int buzzer = 9;
int state = 0;

void setup() {
  Serial.begin(9600);
  pinMode(flame,INPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(buzzer,OUTPUT); 
}

void loop() {
  state = digitalRead(flame);
 
   
  if(state == 0){
    int flamesensor = analogRead(flame);
    Serial.print("Flame Sensor Value");
    Serial.println(flamesensor);
    
       digitalWrite(buzzer,HIGH);
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    delay(500);
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    delay(500);
    Serial.print("Flame Sensor Value");
    Serial.println(flamesensor);
       digitalWrite(buzzer,LOW);
    digitalWrite(blue,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    delay(500);
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    delay(500);
    Serial.print("Flame Sensor Value");
    Serial.println(flamesensor);
       digitalWrite(buzzer,HIGH);
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    delay(500);
    digitalWrite(blue,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    delay(500);
    Serial.print("Flame Sensor Value");
    Serial.println(flamesensor);
       digitalWrite(buzzer,LOW);
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    delay(500);
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    delay(500);
    Serial.print("Flame Sensor Value");
    Serial.println(flamesensor);
       digitalWrite(buzzer,HIGH);
    digitalWrite(blue,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    delay(500);
    digitalWrite(red,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(blue,LOW);
    delay(500);
    Serial.print("Flame Sensor Value");
    Serial.println(flamesensor);
       digitalWrite(buzzer,LOW);
    digitalWrite(green,HIGH);
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    delay(500);
    digitalWrite(blue,HIGH);
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    delay(500);
    if(state == 1){
      digitalWrite(blue,LOW);
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    digitalWrite(buzzer,LOW);
     int flamesensor = analogRead(flame);
    Serial.print("Flame Sensor Value");
    Serial.println(flamesensor);
    delay(1000);
    }
    }    
    
    else{
    digitalWrite(blue,LOW);
    digitalWrite(green,LOW);
    digitalWrite(red,LOW);
    digitalWrite(buzzer,LOW);
     int flamesensor = analogRead(flame);
    Serial.print("Flame Sensor Value");
    Serial.println(flamesensor);
    delay(1000);
    }
}
