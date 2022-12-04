int led = 22;
volatile int state = HIGH;

void setup() {
  pinMode(led,OUTPUT);
  pinMode(3,INPUT);
  attachInterrupt(1,blink,RISING);
}

void loop() {
  digitalWrite(led,state);
}

void blink(){
  state =! state;
}
