#include <SoftwareSerial.h>

#include <LiquidCrystal_I2C.h>

#include <Wire.h>



LiquidCrystal_I2C lcd(0x27, 16, 2);



#define bTx 2

#define bRx 3

#define DC1IN1 4

#define DC1IN2 5

#define EN1 6

#define DC2IN1 7

#define DC2IN2 8

#define EN2 9

#define buzzer 10

#define gas A0

#define PIR 11



#define C 262  // 도

#define D 294  // 레

#define E 330  // 미

#define F 349  // 파

#define G 392  // 솔

#define A 440  // 라

#define B 494  // 시

int tempo = 200;

int melody[26] = { E, D, C, D, E, E, E, D, D, D, E, G, G, E, D, C, D, E, E, E, D, D, E, D, C };  //멜로디를 사이렌으로 짧게 바꿔야함

int x = 150;

byte eye1[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b10001,
  0b11111,
  0b11111,
  0b11111,
  0b11111
};

byte eyeleft[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b11101,
  0b11101,
  0b11101,
  0b10001,
  0b11111
};

byte eyeright[8] = {
  0b11111,
  0b10001,
  0b10001,
  0b10111,
  0b10111,
  0b10111,
  0b10001,
  0b11111
};

byte mouthleft[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b10000,
  0b11000,
  0b01100,
  0b00111,
  0b00011
};

byte mouthright[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00001,
  0b00011,
  0b00110,
  0b11100,
  0b11000
};

byte mouthmid[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b11111
};

byte angry1[8] = {
  0b00000,
  0b00011,
  0b00100,
  0b01000,
  0b10010,
  0b10001,
  0b10000,
  0b10000
};

byte angry2[8] = {
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b10001,
  0b00000
};

byte angry3[8] = {
  0b00000,
  0b11000,
  0b00100,
  0b00010,
  0b01001,
  0b10001,
  0b00001,
  0b00001
};

byte angry4[8] = {
  0b10000,
  0b10000,
  0b10001,
  0b10010,
  0b01000,
  0b00100,
  0b00011,
  0b00000
};

byte angry5[8] = {
  0b00000,
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b00000,
  0b11111,
  0b00000
};

byte angry6[8] = {
  0b00001,
  0b00001,
  0b10001,
  0b01001,
  0b00010,
  0b00100,
  0b11000,
  0b00000
};

byte gas1[8] = {
  0b00000,
  0b00011,
  0b00100,
  0b01000,
  0b10001,
  0b10011,
  0b10001,
  0b10000
};

byte gas2[8] = {
  0b00000,
  0b11111,
  0b00000,
  0b00000,
  0b10001,
  0b10001,
  0b10001,
  0b10001
};

byte gas3[8] = {
  0b00000,
  0b11000,
  0b00100,
  0b00010,
  0b10001,
  0b11001,
  0b10001,
  0b00001
};

byte gas4[8] = {
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b01000,
  0b00100,
  0b00011,
  0b00000
};

byte gas5[8] = {
  0b00100,
  0b00000,
  0b00100,
  0b01110,
  0b11111,
  0b00000,
  0b11111,
  0b00000
};

byte gas6[8] = {
  0b00001,
  0b00001,
  0b00001,
  0b00001,
  0b00010,
  0b00100,
  0b11000,
  0b00000
};

SoftwareSerial bt(bTx, bRx);

char val;





void setup() {

  Serial.begin(9600);

  pinMode(DC1IN1, OUTPUT);

  pinMode(DC1IN2, OUTPUT);

  pinMode(DC2IN1, OUTPUT);

  pinMode(DC2IN2, OUTPUT);

  analogWrite(EN1, 200);

  analogWrite(EN2, 200);

  pinMode(buzzer, OUTPUT);

  pinMode(gas, INPUT);

  pinMode(PIR, INPUT);

  lcd.begin();

  lcd.backlight();

  bt.begin(9600);
}

void movingfaceL() {

  for (int a = 16; a > 4; a -= 4) {

    int b = a - 1;

    int c = a - 2;

    int d = a - 3;

    int e = a - 4;

    int f = a - 5;

    int g = a - 6;

    lcd.clear();

    lcd.createChar(1, eyeleft);

    lcd.createChar(2, mouthleft);

    lcd.createChar(3, mouthmid);

    lcd.createChar(4, mouthright);



    lcd.setCursor(b, 0);  //눈

    lcd.write(1);

    lcd.setCursor(e, 0);

    lcd.write(1);



    lcd.setCursor(b, 1);  //입

    lcd.write(4);

    lcd.setCursor(c, 1);

    lcd.write(3);

    lcd.setCursor(d, 1);

    lcd.write(3);

    lcd.setCursor(e, 1);

    lcd.write(2);

    delay(x);

    lcd.clear();



    lcd.createChar(1, eyeleft);

    lcd.createChar(2, mouthleft);

    lcd.createChar(3, mouthmid);

    lcd.createChar(4, mouthright);



    lcd.setCursor(c, 0);  //눈

    lcd.write(1);

    lcd.setCursor(f, 0);

    lcd.write(1);



    lcd.setCursor(c, 1);  //입

    lcd.write(4);

    lcd.setCursor(d, 1);

    lcd.write(3);

    lcd.setCursor(e, 1);

    lcd.write(3);

    lcd.setCursor(f, 1);

    lcd.write(2);

    delay(x);

    lcd.clear();



    lcd.createChar(1, eyeleft);

    lcd.createChar(2, mouthleft);

    lcd.createChar(3, mouthmid);

    lcd.createChar(4, mouthright);



    lcd.setCursor(d, 0);  //눈

    lcd.write(1);

    lcd.setCursor(g, 0);

    lcd.write(1);



    lcd.setCursor(d, 1);  //입

    lcd.write(4);

    lcd.setCursor(e, 1);

    lcd.write(3);

    lcd.setCursor(f, 1);

    lcd.write(3);

    lcd.setCursor(g, 1);

    lcd.write(2);

    delay(x);

    lcd.clear();
  }
}



void movingfaceR() {

  for (int a = 0; a < 11; a += 4) {

    int b = a + 1;

    int c = a + 2;

    int d = a + 3;

    int e = a + 4;

    int f = a + 5;

    int g = a + 6;

    lcd.clear();

    lcd.createChar(1, eyeright);

    lcd.createChar(2, mouthleft);

    lcd.createChar(3, mouthmid);

    lcd.createChar(4, mouthright);



    lcd.setCursor(b, 0);  //눈

    lcd.write(1);

    lcd.setCursor(e, 0);

    lcd.write(1);



    lcd.setCursor(b, 1);  //입

    lcd.write(2);

    lcd.setCursor(c, 1);

    lcd.write(3);

    lcd.setCursor(d, 1);

    lcd.write(3);

    lcd.setCursor(e, 1);

    lcd.write(4);

    delay(x);

    lcd.clear();

    lcd.createChar(1, eyeright);

    lcd.createChar(2, mouthleft);

    lcd.createChar(3, mouthmid);

    lcd.createChar(4, mouthright);



    lcd.setCursor(c, 0);  //눈

    lcd.write(1);

    lcd.setCursor(f, 0);

    lcd.write(1);



    lcd.setCursor(c, 1);  //입

    lcd.write(2);

    lcd.setCursor(d, 1);

    lcd.write(3);

    lcd.setCursor(e, 1);

    lcd.write(3);

    lcd.setCursor(f, 1);

    lcd.write(4);

    delay(x);

    lcd.clear();

    lcd.createChar(1, eyeright);

    lcd.createChar(2, mouthleft);

    lcd.createChar(3, mouthmid);

    lcd.createChar(4, mouthright);



    lcd.setCursor(d, 0);  //눈

    lcd.write(1);

    lcd.setCursor(g, 0);

    lcd.write(1);



    lcd.setCursor(d, 1);  //입

    lcd.write(2);

    lcd.setCursor(e, 1);

    lcd.write(3);

    lcd.setCursor(f, 1);

    lcd.write(3);

    lcd.setCursor(g, 1);

    lcd.write(4);

    delay(x);
  }
}



void smile() {

  lcd.createChar(1, eye1);

  lcd.createChar(2, mouthleft);

  lcd.createChar(3, mouthmid);

  lcd.createChar(4, mouthright);



  lcd.setCursor(6, 0);  //눈

  lcd.write(1);

  lcd.setCursor(9, 0);

  lcd.write(1);



  lcd.setCursor(6, 1);  //입

  lcd.write(2);

  lcd.setCursor(7, 1);

  lcd.write(3);

  lcd.setCursor(8, 1);

  lcd.write(3);

  lcd.setCursor(9, 1);

  lcd.write(4);
}



void angry() {

  lcd.createChar(1, angry1);

  lcd.createChar(2, angry2);

  lcd.createChar(3, angry3);

  lcd.createChar(4, angry4);

  lcd.createChar(5, angry5);

  lcd.createChar(6, angry6);



  lcd.setCursor(7, 0);

  lcd.write(1);

  lcd.setCursor(8, 0);

  lcd.write(2);

  lcd.setCursor(9, 0);

  lcd.write(3);

  lcd.setCursor(7, 1);

  lcd.write(4);

  lcd.setCursor(8, 1);

  lcd.write(5);

  lcd.setCursor(9, 1);

  lcd.write(6);
}



void warnning() {

  lcd.setCursor(0, 0);

  lcd.print("!GAS!");

  lcd.setCursor(11, 0);

  lcd.print("!GAS!");

  lcd.setCursor(0, 1);

  lcd.print("!evac");

  lcd.setCursor(11, 1);

  lcd.print("uate!");



  lcd.createChar(1, gas1);

  lcd.createChar(2, gas2);

  lcd.createChar(3, gas3);

  lcd.createChar(4, gas4);

  lcd.createChar(5, gas5);

  lcd.createChar(6, gas6);

  lcd.setCursor(7, 0);

  lcd.write(1);

  lcd.setCursor(8, 0);

  lcd.write(2);

  lcd.setCursor(9, 0);

  lcd.write(3);

  lcd.setCursor(7, 1);

  lcd.write(4);

  lcd.setCursor(8, 1);

  lcd.write(5);

  lcd.setCursor(9, 1);

  lcd.write(6);

  delay(300);

  lcd.clear();



  lcd.setCursor(0, 0);

  lcd.print("!GAS!");

  lcd.setCursor(11, 0);

  lcd.print("!GAS!");

  lcd.setCursor(0, 1);

  lcd.print("!evac");

  lcd.setCursor(11, 1);

  lcd.print("uate!");



  lcd.createChar(1, gas1);

  lcd.createChar(2, gas2);

  lcd.createChar(3, gas3);

  lcd.createChar(4, gas4);

  lcd.createChar(5, gas5);

  lcd.createChar(6, gas6);

  lcd.setCursor(6, 0);

  lcd.write(1);

  lcd.setCursor(7, 0);

  lcd.write(2);

  lcd.setCursor(8, 0);

  lcd.write(3);

  lcd.setCursor(6, 1);

  lcd.write(4);

  lcd.setCursor(7, 1);

  lcd.write(5);

  lcd.setCursor(8, 1);

  lcd.write(6);

  delay(300);

  lcd.clear();
}







void gofront() {  //전진

  digitalWrite(DC1IN1, LOW);

  digitalWrite(DC1IN2, HIGH);

  digitalWrite(DC2IN1, HIGH);

  digitalWrite(DC2IN2, LOW);
}



void reverse() {  //후진

  digitalWrite(DC1IN1, HIGH);

  digitalWrite(DC1IN2, LOW);

  digitalWrite(DC2IN1, LOW);

  digitalWrite(DC2IN2, HIGH);
}



void turnright() {  //우회전

  digitalWrite(DC1IN1, HIGH);

  digitalWrite(DC1IN2, LOW);

  digitalWrite(DC2IN1, HIGH);

  digitalWrite(DC2IN2, LOW);
}



void turnleft() {  //좌회전

  digitalWrite(DC1IN1, LOW);

  digitalWrite(DC1IN2, HIGH);

  digitalWrite(DC2IN1, LOW);

  digitalWrite(DC2IN2, HIGH);
}



void sTop() {  //정지

  digitalWrite(DC1IN1, LOW);

  digitalWrite(DC1IN2, LOW);

  digitalWrite(DC2IN1, LOW);

  digitalWrite(DC2IN2, LOW);
}







void loop() {



  Serial.println(analogRead(gas));

  val = digitalRead(PIR);  //인체감지센서 값을 저장

  smile();



  if (val == HIGH) {  //인체감지센서값이 HIGH 이면

    lcd.clear();

    angry();

    for (int i = 0; i < 26; i++) {

      tone(buzzer, melody[i], tempo);

      delay(300);

      if (Serial.available()) {  //도중에 입력을 받으면 노래가 멈춘다

        break;
      }
    }

  }

  else {  //인체가 감지 안되면

    digitalWrite(buzzer, LOW);

    lcd.clear();

    smile();
  }



  if (analogRead(gas) > 70) {  //가스값이 200초과이면

    lcd.clear();

    warnning();

    for (int i = 0; i < 26; i++) {

      tone(buzzer, melody[i], tempo);

      delay(300);

      if (Serial.available()) {  //도중에 입력을 받으면 노래가 멈춘다

        break;
      }

      if (analogRead(gas) < 70) {  //가스값이 70 이하로 떨어지면 노래가 멈춘다

        break;
      }
    }

  }

  else {  //가스값이 200 이하이면

    digitalWrite(buzzer, LOW);

    lcd.clear();

    smile();
  }







  char data;

  if (Serial.available()) {  //bt로 바꿔야함

    data = Serial.read();  //data가 시리얼모니터에 적힌 값



    if (data == '1') {  //1을 적으면

      gofront();  //전진함수

      lcd.clear();

      smile();

      Serial.println("gofornt");
    }

    if (data == '2') {  //2를 적으면

      reverse();  //후진함수

      lcd.clear();

      smile();

      Serial.println("reverse");
    }

    if (data == '5') {  //5을 적으면

      sTop();  //멈춰

      Serial.println("Stop");
    }

    if (data == '3') {

      turnright();

      lcd.clear();

      movingfaceR();

      Serial.println("Right");
    }

    if (data == '4') {

      turnleft();

      lcd.clear();

      movingfaceL();

      Serial.println("Left");
    }
  }
}
