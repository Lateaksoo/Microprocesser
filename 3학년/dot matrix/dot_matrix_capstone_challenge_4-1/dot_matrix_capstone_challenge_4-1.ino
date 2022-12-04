#include <FrequencyTimer2.h>

int pin[17] = {-1,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37};
int col[8]={pin[9],pin[10],pin[11],pin[12],pin[13],pin[14],pin[15],pin[16]};
int row[8]={pin[1],pin[2],pin[3],pin[4],pin[5],pin[6],pin[7],pin[8]};

#define I {\
{0,0,1,1,1,1,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,1,1,1,1,0,0},\
}
#define N {\
{1,0,0,0,0,0,0,1},\
{1,1,0,0,0,0,0,1},\
{1,0,1,0,0,0,0,1},\
{1,0,0,1,0,0,0,1},\
{1,0,0,0,1,0,0,1},\
{1,0,0,0,0,1,0,1},\
{1,0,0,0,0,0,1,1},\
{1,0,0,0,0,0,0,1},\
}
#define D {\
{1,1,1,1,1,1,0,0},\
{1,0,0,0,0,1,1,0},\
{1,0,0,0,0,0,1,1},\
{1,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,0,1},\
{1,0,0,0,0,0,1,1},\
{1,0,0,0,0,1,1,0},\
{1,1,1,1,1,1,0,0},\
}
#define U {\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
{0,1,0,0,0,0,1,0},\
{0,0,1,1,1,1,0,0},\
}
#define K {\
{1,1,0,0,0,1,0,0},\
{1,1,0,0,1,0,0,0},\
{1,1,0,1,0,0,0,0},\
{1,1,1,0,0,0,0,0},\
{1,1,1,0,0,0,0,0},\
{1,1,0,1,0,0,0,0},\
{1,1,0,0,1,0,0,0},\
{1,1,0,0,0,1,0,0},\
}
#define M {\
{0,1,1,0,0,1,1,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
}
#define LOVE {\
{0,1,1,0,0,1,1,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,1,1,0,0,1},\
{1,0,0,0,0,0,0,1},\
{0,1,0,0,0,0,1,0},\
{0,0,1,0,0,1,0,0},\
{0,0,0,1,1,0,0,0},\
{0,0,0,0,0,0,0,0},\
}

int sw = 2;
byte coli = 0;
byte LED[8][8];
int pattern = 0;

const int Patterns_no = 8;
byte patterns[Patterns_no][8][8] ={ I,N,D,U,K,M,K,LOVE};


void setup() {
  for(int i=1;i<=16;i++){ //핀모드 설정 
    pinMode(pin[i],OUTPUT);
  }

  for(int i=0;i<8;i++){ //초기화 
    digitalWrite(row[i],LOW);
    digitalWrite(col[i],HIGH);
  }
  



  FrequencyTimer2::setOnOverflow(display);

  pinMode(sw,INPUT);

//  Pattern_output(pattern);
}

void loop() {
  int sw_status = digitalRead(sw);

  if(sw_status == HIGH){
    pattern++;
    if(pattern == 8){
      pattern = 0;
    }
    else{
      
      delay(300);
    }
  }
  Pattern_output(pattern);

}



void Pattern_output(int pattern){
  for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
      LED[i][j] = patterns[pattern][i][j];
    }
  }
}

void display(){
  digitalWrite( col[coli],HIGH);
  coli++;
  
  if(coli==8){
    coli=0;
  }
  
  for(int row1=0;row1<8;row1++){
    if(LED[coli][7-row1] == 1){ //7-을 안하면 좌우가 반전된다 
      digitalWrite(row[row1],HIGH);
    }
    else{
      digitalWrite(row[row1],LOW);
    }
  }
  digitalWrite(col[coli],LOW);
}
