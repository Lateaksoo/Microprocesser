int pin[17] = {-1,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};
int col[8]={pin[9],pin[10],pin[11],pin[12],pin[13],pin[14],pin[15],pin[16]};
int row[8]={pin[1],pin[2],pin[3],pin[4],pin[5],pin[6],pin[7],pin[8]};

void setup() {
for(int i=1;i<=16;i++){
    pinMode(pin[i],OUTPUT);
  }

}

void loop() {
   for(int m=0; m<8;m++){ //초기화 
    digitalWrite(row[m],LOW);
    digitalWrite(col[m],HIGH);
  }
  
 for(int j=0;j<8;j++){ //한줄씩 누적해서 on
  digitalWrite(row[j],HIGH);

  for(int k=0;k<8;k++){
    digitalWrite(col[k],LOW);
  }
  delay(500);
}
 

//한줄씩 누적해서 off

  for(int b=7;b>=0;b--){
    digitalWrite(row[b],LOW);
    delay(500);
  }
  
}
  
