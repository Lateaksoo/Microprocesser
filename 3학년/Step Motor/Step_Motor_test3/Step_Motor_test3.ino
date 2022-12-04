#define IN1 39
#define IN2 41
#define IN3 43
#define IN4 45

int Steps = 0;
int steps_left=4095;

boolean Direction = true;
unsigned long last_time;
unsigned long currentMillis;
long time;

void setup() {
  Serial.begin(9600);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop() {
  Direction = 0;
  while(steps_left>0){
    currentMillis = micros();
    if(currentMillis-last_time>=1000)
    {
      stepper(1);
      time=time+micros()-last_time;
      last_time=micros();
      steps_left--;
     
    }
  }

  Serial.println(Steps);
  Serial.println("Wait ");
  delay(2000);

  steps_left=4095;
}

void stepper(int xw){
  for(int x=0;x<xw;x++){
    switch(Steps){
      case 0: runStep(LOW,LOW,LOW,HIGH); break;
      case 1: runStep(LOW,LOW,HIGH,HIGH); break;
      case 2: runStep(LOW,LOW,HIGH,LOW); break;
      case 3: runStep(LOW,HIGH,HIGH,LOW); break;
      case 4: runStep(LOW,HIGH,LOW,LOW); break;
      case 5: runStep(HIGH,HIGH,LOW,LOW); break;
      case 6: runStep(HIGH,LOW,LOW,LOW); break;
      case 7: runStep(HIGH,LOW,LOW,HIGH); break;
      default : runStep(LOW,LOW,LOW,LOW);break;
    }
    SetDirection();
  }
}

void runStep(int value1, int value2, int value3, int value4)
{
  digitalWrite(IN1, value1);
  digitalWrite(IN2, value2);
  digitalWrite(IN3, value3);
  digitalWrite(IN4, value4);
}

void SetDirection()
{
  if(Direction==1) {Steps++;}
  if(Direction==0) {Steps--;}
  if(Steps>7) {Steps=0;}
  if(Steps<0) {Steps=7;}
}
