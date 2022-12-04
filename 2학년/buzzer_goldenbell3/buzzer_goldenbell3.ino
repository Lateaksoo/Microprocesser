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
int buzzer = 0;
void setup() {
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(9,OUTPUT);
 pinMode(10,OUTPUT);
 pinMode(11,OUTPUT);
 pinMode(12,OUTPUT);
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
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    if(digitalRead(button4)==HIGH){
    break;
    }
  }
  }
  while(digitalRead(button2)==HIGH){
    for(int i=0; i<8; i++){
    tone(buzzer,melody2[i],tempo);
    delay(300);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(11,LOW);
    digitalWrite(9,LOW);
    digitalWrite(8,LOW);
    if(digitalRead(button4)==HIGH){
    break;
    }
  }
  }
  while(digitalRead(button3)==HIGH){
    for(int i=0; i<8; i++){
    tone(buzzer,melody3[i],tempo);
    delay(300);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(11,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    if(digitalRead(button4)==HIGH){
    break;
     }
    }
  }
  while(digitalRead(button4)==HIGH){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(10,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(11,HIGH);
    delay(100);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(10,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(11,HIGH);
    delay(100);
}
while(digitalRead(button3)==LOW&&digitalRead(button2)==LOW&&digitalRead(button1)==LOW){
noTone(buzzer);
digitalWrite(12,HIGH);
digitalWrite(11,HIGH);
digitalWrite(10,HIGH);
digitalWrite(9,HIGH);
digitalWrite(8,HIGH);
digitalWrite(7,HIGH);
digitalWrite(5,HIGH);
digitalWrite(4,HIGH);
}
}
