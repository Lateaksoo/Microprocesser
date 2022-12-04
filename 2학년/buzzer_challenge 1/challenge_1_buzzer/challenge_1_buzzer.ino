#define C 262 // 도 
#define D 294 // 레 
#define E 330 // 미 
#define F 349 // 파 
#define G 392 // 솔 
#define A 440 // 라 
#define B 494 // 시 
int tempo = 200;
int melody[26]={E,D,C,D,E,E,E,D,D,D,E,G,G,E,D,C,D,E,E,E,D,D,E,D,C};
void setup() {
  pinMode(4,OUTPUT);
 for(int i=0; i<26; i++){
    tone(4,melody[i],tempo);
    delay(300);
 }
}

void loop() {
  
    
  
}
