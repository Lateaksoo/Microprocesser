int relay=13; 

void setup() {
  Serial.begin(9600);
  pinMode(relay, OUTPUT);
  
  digitalWrite(relay,HIGH);
  Serial.println("1을 입력하면 소리가 나고 2를 입력하면 소리가 꺼집니다.");
}

void loop() {
  if(Serial.available()){
    switch(Serial.read()){
      case '1':
      digitalWrite(relay,HIGH);
      Serial.println("Buzzer on");
      
      delay(1000);
      break;
      case '2':
      digitalWrite(relay,LOW);
      Serial.println("Buzzer off");
     
      delay(1000);
      break;
    }
  }
}
