int trig = 8;
int echo = 9;
int buzzer = 5;
int red = 4;
int green = 3;
int blue = 2;

void setup() {
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(buzzer,OUTPUT);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  long duration,distance;
  
  digitalWrite(trig,LOW);
  delay(100);
  digitalWrite(trig,HIGH);
  delay(100);
  digitalWrite(trig,LOW);

  duration = pulseIn(echo,HIGH);
  distance = duration*17/1000;

  if(distance>30)
  {
    digitalWrite(buzzer,HIGH);
    digitalWrite(green,HIGH);
    delay(1000);
    digitalWrite(buzzer,LOW);
    digitalWrite(green,LOW);
    delay(1000);
  }
  if(distance<29&&distance>11){
    digitalWrite(buzzer,HIGH);
    digitalWrite(blue,HIGH);
    delay(500);
    digitalWrite(buzzer,LOW);
    digitalWrite(blue,LOW);
    delay(500);
  }
  if(distance<10){
    digitalWrite(buzzer,HIGH);
    digitalWrite(red,HIGH);
  }
  else
  {
    digitalWrite(red,LOW);
    digitalWrite(blue,LOW);
    digitalWrite(green,LOW);
  }
}
