int pin[17] = {-1,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};

int col[8]={pin[9],pin[10],pin[11],pin[12],pin[13],pin[14],pin[15],pin[16]};

int row[8]={pin[1],pin[2],pin[3],pin[4],pin[5],pin[6],pin[7],pin[8]};

int sw = 2;

volatile int state = HIGH;

volatile int state1 = LOW;

void setup() {

  for(int i=1;i<=16;i++){ //핀모드설정 

    pinMode(pin[i],OUTPUT);

  }

  pinMode(sw,INPUT_PULLUP);

  for(int m=0; m<8;m++){ // 초기화 

    digitalWrite(row[m],LOW);

    digitalWrite(col[m],HIGH);

  }

  attachInterrupt(0,cnt,FALLING);

}

//col이 행 row가 열 1열 led 켜기 

void loop() {

digitalWrite(col[0],state);

  digitalWrite(col[0],state1);

  for(int i=0;i<6;i++){

    digitalWrite(col[i],state);

  }

  digitalWrite(col[0],state);

  for(int j=0;j<8;j++){

    digitalWrite(row[j],state);

  }

  

}

 

void cnt(){

   state =! state;

   state1 =! state1;

}