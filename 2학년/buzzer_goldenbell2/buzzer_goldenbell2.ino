#define C 262 
#define D 294 
#define E 330 
#define F 349 
#define G 392 
#define A 440 
#define B 494 
int tempo = 200;
int melody1[26]={E,D,C,D,E,E,E,D,D,D,E,G,G,E,D,C,D,E,E,E,D,D,E,D,C};
int melody2[8]={C,D,E,F,G,A,B};
int melody3[8]={B,A,G,F,E,D,C};
int button1 = 1;
int button2 = 2;
int button3 = 3;
int button4 = 13;
int red = 9; //빨간색 led 핀
int green = 10; //초록색 led핀
int blue = 11; // 파란색 led핀
int buzzer = 0;


void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(button1,INPUT);
  pinMode(button2,INPUT);
  pinMode(button3,INPUT);
  pinMode(button4,INPUT);
  
  }

void loop() {
  
   while(digitalRead(button1)==HIGH){
    for(int i=0; i<26; i++){
    tone(buzzer,melody1[i],tempo);
    delay(300);
    digitalWrite(red,HIGH);
    delay(100);
    digitalWrite(red,LOW);
    delay(100);  
    if(digitalRead(button4)==HIGH){
      break;
    }
  }}
  while(digitalRead(button2)==HIGH){
  for(int i=0; i<8; i++){
    tone(buzzer,melody2[i],tempo);
    delay(100);
    digitalWrite(green,HIGH);
    delay(100);
    digitalWrite(green,LOW);
    delay(100);
    if(digitalRead(button4)==HIGH){
    break;
  
    }
  }}
  while(digitalRead(button3)==HIGH){
  for(int i=0; i<8; i++){
    tone(buzzer,melody3[i],tempo);
    
    digitalWrite(blue,HIGH);
    delay(100);
    digitalWrite(blue,LOW);
    delay(100);
    if(digitalRead(button4)==HIGH){
    break;
  }}}
while(digitalRead(button3)==LOW&&digitalRead(button2)==LOW&&digitalRead(button1)==LOW){
noTone(buzzer);
digitalWrite(red,LOW);
digitalWrite(blue,LOW);
digitalWrite(green,LOW);
}

}
