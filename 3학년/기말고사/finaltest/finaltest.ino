/* 
모터 정의
*/
#define IN1 22
#define IN2 24
#define IN3 26
#define IN4 28

int Steps = 0;
int steps_left;
boolean Direction = true;

unsigned long last_time;
unsigned long currentMillis;
long time;


/* 
틸트센서
*/
const int Tilt = 3;

/*
스위치
*/
const int Switch = 2;

volatile int state = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  noInterrupts();
  interrupts();
  attachInterrupt(digitalPinToInterrupt(Switch), SwitchStopMotor, FALLING);
}


void Forward() { //시계방향 돌기
  Direction = 0;
  int reverse = 4095;
  while (reverse > 0) {
    currentMillis = micros();
    if (currentMillis - last_time >= 1000) {
      stepper(1);
      time = time + micros() - last_time;
      last_time = micros();
      reverse--;
    }
  }
  reverse = 4095;
}

void Reverse() { // 반시계방향돌기 
  Direction = 1;
  int forward = 4095;
  while (forward > 0) {
    currentMillis = micros();
    if (currentMillis - last_time >= 1000) {
      stepper(1);
      time = time + micros() - last_time;
      last_time = micros();
      forward--;
    }
  }
  forward = 4095;
}

void stepper(int xw) {
  for (int x = 0; x < xw; x++) {
    switch (Steps) {
      case 0: runStep(LOW, LOW, LOW, HIGH); break;
      case 1: runStep(LOW, LOW, HIGH, HIGH); break;
      case 2: runStep(LOW, LOW, HIGH, LOW); break;
      case 3: runStep(LOW, HIGH, HIGH, LOW); break;
      case 4: runStep(LOW, HIGH, LOW, LOW); break;
      case 5: runStep(HIGH, HIGH, LOW, LOW); break;
      case 6: runStep(HIGH, LOW, LOW, LOW); break;
      case 7: runStep(HIGH, LOW, LOW, HIGH); break;
      default: runStep(LOW, LOW, LOW, LOW); break;
    }
    SetDirection();
  }
}

void runStep(int value1, int value2, int value3, int value4) {
  digitalWrite(IN1, value1);
  digitalWrite(IN2, value2);
  digitalWrite(IN3, value3);
  digitalWrite(IN4, value4);
}

void SetDirection() {
  if (Direction == 1) { Steps++; }
  if (Direction == 0) { Steps--; }
  if (Steps > 7) { Steps = 0; }
  if (Steps < 0) { Steps = 7; }
}



void SwitchStopMotor() {
  while (1) {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    Serial.println("Step Motor Stop");
    if (digitalRead(2) == state) {
      break;
    }
  }
  state = !state;
}

void loop() {
  if (digitalRead(Tilt) == HIGH) {
    Forward();
  } else {
    Serial.println("Counterclockwise");
    Reverse();
  }
}