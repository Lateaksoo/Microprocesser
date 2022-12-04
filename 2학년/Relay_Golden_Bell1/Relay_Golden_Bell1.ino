int RELAY=5;
int TRIG=6;
int ECHO=7;
void setup() {
  Serial.begin(9600);
  pinMode(RELAY,OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
 digitalWrite(TRIG,HIGH);
 delay(10);
 digitalWrite(TRIG,LOW);
 
 float duration = pulseIn(ECHO, HIGH);
 float distance = ((float)(340*duration)/10000)/2;

 Serial.println("거리:");
 Serial.println(distance);
 Serial.println("cm");

 
 if(distance <20)
 {digitalWrite(RELAY, HIGH);}
 else if(distance >20)
 {digitalWrite(RELAY, LOW);}
 delay(1000);
 
}
