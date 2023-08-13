#include <LiquidCrystal.h> 
LiquidCrystal lcd(22,23,24,25,26,27);

#define C 262 // 도 
#define D 294 // 레 
#define E 330 // 미 
#define F 349 // 파 
#define G 392 // 솔 
#define A 440 // 라 
#define B 494 // 시 
int tempo = 200;
int melody1[26]={E,D,C,D,E,E,E,D,D,D,E,G,G,E,D,C,D,E,E,E,D,D,E,D,C};
 
int y; //연
int m; //월 
int d; //일 
int h; //시 
int b; //분 
int s; //초 
int milli;


int ah=0; //알람 시 
int ab=0; //알람 분 
int as=0; //알람 초 
 
int bt1=29; //초 +1 버튼 or 일+1
int bt2=30; //분 +1 버튼 or 월+1
int bt3=31; //시 +1 버튼 or 년+1
int bt4=32;//시간설정
int bt5=33;//날짜설정
int bt6=34;//알람설정
 
int buzzer=35;
 
 
 
 
void setup() {
 lcd.begin(16, 2); 
  pinMode(bt1,INPUT); 
  pinMode(bt2,INPUT); 
  pinMode(bt3,INPUT); 
  pinMode(bt4,INPUT); 
  pinMode(bt5,INPUT); 
  pinMode(bt6,INPUT);
  
  pinMode(buzzer,OUTPUT);
y=2022;
m=5;
d=29;
h=1;
b=1;
s=1;
}
 
void alramwatch() { //알람시계 함수
lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("alram Setting");
  lcd.setCursor(0,1);
 
{ lcd.setCursor(0,1); //lcd의 두번째 줄에입력
  lcd.print("Time"); 
  lcd.print(":"); 
  if(ah<10){           //자리수 설정 부분
  lcd.setCursor(5,1);
  lcd.print("0");
  lcd.print(ah);
  lcd.print(":");
}
else if(ah>=10){
  lcd.print(ah); 
  lcd.print(":");
  } 
if(ab<10){
  lcd.setCursor(8,1);
  lcd.print("0");
  lcd.print(ab);
  lcd.print(":");
}
else if(ab>=10){
  lcd.print(ab); 
  lcd.print(":");
  }
   if(as<10){
  lcd.setCursor(11,1);
  lcd.print("0");
  lcd.print(as);
}
else if(as>=10){
  lcd.print(as); 
  }

 
 
if (as == 60){ 
    as=0; 
    ab=ab+1; 
  }
 
  if (ab == 60){ 
    ab=0; 
    ah=ah+1; 
  } 
  if(ah==24) 
  { 
    ah=0; 
    ab=0; 
    as=0; 
    d=d+1; 
  } 
 
  /////////알람시계 설정하는동안 원래시간도 계속 흐른다  
   milli++;
   delay(100);
   if(milli==10){
    s=s+1;
    milli=0;  
   }
  if (s == 60){  //초가 60초가되면 초기화 +1분 
    s=0; 
    b=b+1; 
  }
 
  if (b == 60){ //분이 60분이 되면 초기화 +1시 
    b=0; 
    h=h+1; 
  } 
  if(h==24) //시간이 24시가 되면 초기화 +1일 
  { 
    h=0; 
    b=0; 
    s=0; 
    d=d+1; 
  }if (s == 60){  //초가 60초가되면 초기화 +1분 
    s=0; 
    b=b+1; 
  }
 
  if (b == 60){ //분이 60분이 되면 초기화 +1시 
    b=0; 
    h=h+1; 
  } 
  if(h==24) //시간이 24시가 되면 초기화 +1일 
  { 
    h=0; 
    b=0; 
    s=0; 
    d=d+1; 
  }
}
 
  
  if(digitalRead(bt1)==HIGH) 
  { 
    as=as+1; 
    if(as==61){
      as=0;
      ab=ab+1; 
    }
  } 
  if(digitalRead(bt2)==HIGH) 
  { 
    ab=ab+1; 
    if(ab==61){
      ab=0;
      ah=ah+1;
    }
  } 
  if(digitalRead(bt3)==HIGH) 
  { 
    ah=ah+1; 
    if(ah==25){
      ah=0;
      
    }
  }  
}
 
 
void watch(){         //시계 부분 
 lcd.setCursor(0,1);  //lcd의 두번째 줄에입력


  lcd.print("Time"); 
  lcd.print(":"); 
  
  if(h<10){           //자리수 설정 부분
  lcd.setCursor(5,1);
  lcd.print("0");
  lcd.print(h);
  lcd.print(":");
}
else if(h>=10){
  lcd.print(h); 
  lcd.print(":");
  } 
if(b<10){
  lcd.setCursor(8,1);
  lcd.print("0");
  lcd.print(b);
  lcd.print(":");
}
else if(b>=10){
  lcd.print(b); 
  lcd.print(":");
  }
   if(s<10){
  lcd.setCursor(11,1);
  lcd.print("0");
  lcd.print(s);
}
else if(s>=10){
  lcd.print(s); 
  }
 
milli++;
delay(100);
if(milli==10){
    s=s+1;
    milli=0;  
   }
 
if (s == 60){  //초가 60초가되면 초기화 +1분 
    s=0; 
    b=b+1; 
  }
 
  if (b == 60){ //분이 60분이 되면 초기화 +1시 
    b=0; 
    h=h+1; 
  } 
  if(h==24) //시간이 24시가 되면 초기화 +1일 
  { 
    h=0; 
    b=0; 
    s=0; 
    d=d+1; 
  }
  if(digitalRead(bt4)==HIGH){ //시간 조정 
  if(digitalRead(bt1)==HIGH) 
  { 
    s=s+1 ;
     
  } 
  if(digitalRead(bt2)==HIGH) 
  { 
    b=b+1; 
   
  } 
  if(digitalRead(bt3)==HIGH) 
  { 
    h=h+1; 
   
  } 
}

}
 
void date() {
  // 날짜 부분
  lcd.setCursor(0, 0); // lcd 첫번째 줄에 표시
  lcd.print("Date");
  lcd.print(":");
  lcd.print(y);
  lcd.print(":");

  if (m < 10) { // 달이 한자리수일때 앞에 0표시 
    lcd.setCursor(10, 0);
    lcd.print("0");
    lcd.print(m);
  } else if (m >= 10) { // 달이 두자리수일때 
    lcd.print(m);
  }

  if (d < 10) { // 일이 한자리수일때 앞에 0이 표시 
    lcd.setCursor(12, 0);
    lcd.print(":");
    lcd.print("0");
    lcd.print(d);
  } else if (d >= 10) { // 두자리수일때 
    lcd.print(":");
    lcd.print(d);
  }

  if (digitalRead(bt3) == HIGH) {
    y = y + 1;
  }
}

 
void ringring(){ //알람부분 
  if(ah==h && ab==b && as==s){ //설정시간과 현재시간이 같으면 알람이 울린다 
   
   lcd.clear();
   lcd.print("Wake Up!");
    for(int i=0;i<26;i++){
      watch();
      tone(buzzer,melody1[i],tempo);
      ah=0;
      ab=0;
      as=0;
    }
  }
}
 
 
void loop() {
if(digitalRead(bt6)==HIGH){ //알람시계 부분 
  alramwatch();
  delay(100);//이게 없으면 버튼6번 눌렀을때 화면이 너무 깜빡거림 
}
else{
  
  watch();
  date(); 
  ringring();
}
 
}
