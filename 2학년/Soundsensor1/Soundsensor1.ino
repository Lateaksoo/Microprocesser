int sensor= A2;
int led1 = 28;
int led2 = 29;
int led3=30;
void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);             
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

}

void loop() {
 int Sound = analogRead(sensor);

 Serial.println(Sound);

 if(Sound>9){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
 }
 else if(Sound>6){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
 }
 else if(Sound>3){
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
 }
else if (Sound<3){
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
}
}
