int pin[17] = {-1,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};
int col[8]={pin[9],pin[10],pin[11],pin[12],pin[13],pin[14],pin[15],pin[16]};
int row[8]={pin[1],pin[2],pin[3],pin[4],pin[5],pin[6],pin[7],pin[8]};
int sw = 2;
int Flag = 0; //버튼눌렸을때 flag로 신호를 정확히 입력받기
int gocount = 0;
int backcount = 7;
int g=0; //go 앞으로 갈때
int b=7; //back 다시 돌아 올때

void setup() {
  for(int i=1;i<=16;i++){
    pinMode(pin[i],OUTPUT);
  }
  pinMode(sw,INPUT);
  Serial.begin(9600);
  attachInterrupt(0,cnt,CHANGE); //change일때 인식이 잘된다
}

void loop() {

}
void on(int row_led, int col_led){ //한줄씩 키는함수
  digitalWrite(row[row_led],HIGH);
  digitalWrite(col[col_led],LOW);
}

void off(int row_led){ //한줄씩 끄는 함수 
  digitalWrite(row[row_led],LOW);
}

void dot_led(int row_led, int col_led){
for(int m=0; m<8;m++){
    digitalWrite(row[m],LOW);
    digitalWrite(col[m],HIGH);
  }
  digitalWrite(row[row_led],HIGH);
  digitalWrite(col[col_led],LOW);
}


void cnt(){ // 한점씩 왔다갔다
      if(digitalRead(sw)==HIGH){ 
        if(Flag==0){
          if(g>=8){
           Flag = 1;
        for(int i=0;i<8;i++){
          on(b,i);
        }
           b--;
           Serial.println(b);
        }
          else if(g<8){
          Flag = 1;
          dot_led(g,gocount);
          Serial.println("스위치눌림");
          gocount++;
          if(gocount==8){
            gocount=0;
            g=g+1;
          }
        }
      }
        else{
        }
      }
      else{
        Flag=0;
        Serial.println("스위치안눌림");
          } 
      }
