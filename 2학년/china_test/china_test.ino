#define C 262 // 도 
#define D 294 // 레 
#define E 330 // 미 
#define F 349 // 파 
#define G 392 // 솔 
#define A 440 // 라 
#define B 494 // 시 
#define C1 530   // 높은도 
int tempo = 1000;
int melody[18]={C,D,E,F,G,A,B,C1,C,D,E,F,G,A,B,C1};
int led = 8;//led 
int buzzer = 6;//buzzer
int tilt = 9;//tilt sensor
int sw = 4;//button
void setup() {
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(tilt,INPUT);
  pinMode(sw,INPUT);
 Serial.begin(9600);
 

}
void loop() {
  
  while(digitalRead(tilt)==HIGH){
  for(int i=0; i<18; i++){
    if(digitalRead(sw)==HIGH){
      digitalWrite(led,HIGH);
      break;
    }
    tone(6,melody[i],tempo);
    delay(1000); 
  } 
  break; 
  }
  while(digitalRead(tilt)==HIGH){
    noTone(6);
  }
}
