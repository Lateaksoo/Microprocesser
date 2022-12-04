#define C 262 // 도 
#define D 294 // 레 
#define E 330 // 미 
#define F 349 // 파 
#define G 392 // 솔 
#define A 440 // 라 
#define B 494 // 시 
int buzzer =  7;
void setup() {
pinMode(7, OUTPUT);            
pinMode(9, INPUT);  
pinMode(10, INPUT);  
pinMode(11, INPUT);
pinMode(12, INPUT);
pinMode(13, INPUT);

}

void loop() {
 if (digitalRead(9) == HIGH) {    
tone (7, 262 ,100);      }     
else if (digitalRead(10) == HIGH) {      
tone (7, 294 ,100);}
else if (digitalRead(11) == HIGH) {      
tone (7, 330 ,100);}
else if (digitalRead(12) == HIGH) {      
tone (7, 349 ,100);}
else if (digitalRead(13) == HIGH) {      
tone (7, 392 ,100);}
else{
noTone(3);
}
}
