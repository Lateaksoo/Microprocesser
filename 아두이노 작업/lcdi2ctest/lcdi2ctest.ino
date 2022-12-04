#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sw1 = 7;
int sw2 = 6;
int sw3 = 5;

int x = 150;
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
               
void setup() {
  lcd.begin();
  lcd.backlight();
  pinMode(sw1,INPUT);
  pinMode(sw2,INPUT);
  pinMode(sw3,INPUT);
}

void movingfaceL(){
  for(int a=16; a>4;a-=4){
  int b = a - 1;
  int c = a - 2;
  int d = a - 3;
  int e = a - 4;
  int f = a - 5;
  int g = a - 6;
  lcd.clear();
  lcd.createChar(1,eyeleft);
  lcd.createChar(2,mouthleft);
  lcd.createChar(3,mouthmid);
  lcd.createChar(4,mouthright);
  
  lcd.setCursor(b,0); //눈 
  lcd.write(1);
  lcd.setCursor(e,0);
  lcd.write(1);

  lcd.setCursor(b,1); //입 
  lcd.write(4);
  lcd.setCursor(c,1);
  lcd.write(3);
  lcd.setCursor(d,1);
  lcd.write(3);
  lcd.setCursor(e,1);
  lcd.write(2);
  delay(x);
  lcd.clear();
  
  lcd.createChar(1,eyeleft);
  lcd.createChar(2,mouthleft);
  lcd.createChar(3,mouthmid);
  lcd.createChar(4,mouthright);
  
  lcd.setCursor(c,0); //눈 
  lcd.write(1);
  lcd.setCursor(f,0);
  lcd.write(1);

  lcd.setCursor(c,1); //입 
  lcd.write(4);
  lcd.setCursor(d,1);
  lcd.write(3);
  lcd.setCursor(e,1);
  lcd.write(3);
  lcd.setCursor(f,1);
  lcd.write(2);
  delay(x);
  lcd.clear();
  
  lcd.createChar(1,eyeleft);
  lcd.createChar(2,mouthleft);
  lcd.createChar(3,mouthmid);
  lcd.createChar(4,mouthright);
  
  lcd.setCursor(d,0); //눈 
  lcd.write(1);
  lcd.setCursor(g,0);
  lcd.write(1);

  lcd.setCursor(d,1); //입 
  lcd.write(4);
  lcd.setCursor(e,1);
  lcd.write(3);
  lcd.setCursor(f,1);
  lcd.write(3);
  lcd.setCursor(g,1);
  lcd.write(2);
  delay(x);
  lcd.clear();
  }
}

void movingfaceR(){
  for(int a=0;a<11;a+=4){
  int b = a + 1;
  int c = a + 2;
  int d = a + 3;
  int e = a + 4;
  int f = a + 5;
  int g = a + 6;
  lcd.clear();
 lcd.createChar(1,eyeright);
  lcd.createChar(2,mouthleft);
  lcd.createChar(3,mouthmid);
  lcd.createChar(4,mouthright);
 
  lcd.setCursor(b,0); //눈 
  lcd.write(1);
  lcd.setCursor(e,0);
  lcd.write(1);

  lcd.setCursor(b,1); //입 
  lcd.write(2);
  lcd.setCursor(c,1);
  lcd.write(3);
  lcd.setCursor(d,1);
  lcd.write(3);
  lcd.setCursor(e,1);
  lcd.write(4);
  delay(x);
  lcd.clear();
  lcd.createChar(1,eyeright);
  lcd.createChar(2,mouthleft);
  lcd.createChar(3,mouthmid);
  lcd.createChar(4,mouthright);
 
  lcd.setCursor(c,0); //눈 
  lcd.write(1);
  lcd.setCursor(f,0);
  lcd.write(1);

  lcd.setCursor(c,1); //입 
  lcd.write(2);
  lcd.setCursor(d,1);
  lcd.write(3);
  lcd.setCursor(e,1);
  lcd.write(3);
  lcd.setCursor(f,1);
  lcd.write(4);
  delay(x);
  lcd.clear();
  lcd.createChar(1,eyeright);
  lcd.createChar(2,mouthleft);
  lcd.createChar(3,mouthmid);
  lcd.createChar(4,mouthright);
 
  lcd.setCursor(d,0); //눈 
  lcd.write(1);
  lcd.setCursor(g,0);
  lcd.write(1);

  lcd.setCursor(d,1); //입 
  lcd.write(2);
  lcd.setCursor(e,1);
  lcd.write(3);
  lcd.setCursor(f,1);
  lcd.write(3);
  lcd.setCursor(g,1);
  lcd.write(4);
  delay(x);
  
  }
}

void smile(){
  lcd.createChar(1,eye1);
  lcd.createChar(2,mouthleft);
  lcd.createChar(3,mouthmid);
  lcd.createChar(4,mouthright);
 
  lcd.setCursor(6,0); //눈 
  lcd.write(1);
  lcd.setCursor(9,0);
  lcd.write(1);

  lcd.setCursor(6,1); //입 
  lcd.write(2);
  lcd.setCursor(7,1);
  lcd.write(3);
  lcd.setCursor(8,1);
  lcd.write(3);
  lcd.setCursor(9,1);
  lcd.write(4);
}

void angry(){
  lcd.createChar(1,angry1);
  lcd.createChar(2,angry2);
  lcd.createChar(3,angry3);
  lcd.createChar(4,angry4);
  lcd.createChar(5,angry5);
  lcd.createChar(6,angry6);
  
  lcd.setCursor(7,0);
  lcd.write(1);
  lcd.setCursor(8,0);
  lcd.write(2);
  lcd.setCursor(9,0);
  lcd.write(3);
  lcd.setCursor(7,1);
  lcd.write(4);
  lcd.setCursor(8,1);
  lcd.write(5);
  lcd.setCursor(9,1);
  lcd.write(6);
}
void gas(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("!GAS!");
  lcd.setCursor(11,0);
  lcd.print("!GAS!");
  lcd.setCursor(0,1);
  lcd.print("!evac");
  lcd.setCursor(11,1);
  lcd.print("uate!");
  
  lcd.createChar(1,gas1);
  lcd.createChar(2,gas2);
  lcd.createChar(3,gas3);
  lcd.createChar(4,gas4);
  lcd.createChar(5,gas5);
  lcd.createChar(6,gas6);
  lcd.setCursor(7,0);
  lcd.write(1);
  lcd.setCursor(8,0);
  lcd.write(2);
  lcd.setCursor(9,0);
  lcd.write(3);
  lcd.setCursor(7,1);
  lcd.write(4);
  lcd.setCursor(8,1);
  lcd.write(5);
  lcd.setCursor(9,1);
  lcd.write(6);
  delay(300);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("!GAS!");
  lcd.setCursor(11,0);
  lcd.print("!GAS!");
  lcd.setCursor(0,1);
  lcd.print("!evac");
  lcd.setCursor(11,1);
  lcd.print("uate!");
  
  lcd.createChar(1,gas1);
  lcd.createChar(2,gas2);
  lcd.createChar(3,gas3);
  lcd.createChar(4,gas4);
  lcd.createChar(5,gas5);
  lcd.createChar(6,gas6);
  lcd.setCursor(6,0);
  lcd.write(1);
  lcd.setCursor(7,0);
  lcd.write(2);
  lcd.setCursor(8,0);
  lcd.write(3);
  lcd.setCursor(6,1);
  lcd.write(4);
  lcd.setCursor(7,1);
  lcd.write(5);
  lcd.setCursor(8,1);
  lcd.write(6);
  delay(300);
  lcd.clear();
}

void loop() {
 
  smile();


  
  if(digitalRead(sw1) == HIGH){
    gas();
    gas();
    
  }
  if(digitalRead(sw2) == HIGH){
    movingfaceR();
   lcd.clear();
  }
  if(digitalRead(sw3) == HIGH){
    movingfaceL(); 
   lcd.clear();
  }
}
