int buzzer = 28;
int LED1 = 22;
int LED2 = 23;
int sw = 2;
int LED1_state = HIGH;
int switch_state;

void setup() {
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(sw,INPUT);

}

void loop() {
  swrutine();
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,LOW);
  delay(2000);
  swrutine();
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,HIGH);
  delay(2000);
 swrutine();
}

void swrutine(){
  if(digitalRead(sw) == HIGH){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }
}
