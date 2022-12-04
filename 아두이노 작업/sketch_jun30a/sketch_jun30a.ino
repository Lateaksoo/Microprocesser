int red =24;
int green = 23;
int blue = 22;
int sw=26;
int buzzer=25;
byte LED[3]{22,23,24};

unsigned long previousTimebuzzer = 0;
unsigned long buzzerdelay = 1000;
byte buzzerstate = LOW;

unsigned long previousTimeled = 0;
unsigned long leddelay = 500;
byte ledstate = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(sw,INPUT);
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(buzzer,OUTPUT); 
}

void loop() {
   unsigned long timeNow = millis();
if(digitalRead(sw)==HIGH){
  if(timeNow - previousTimebuzzer > buzzerdelay){
    previousTimebuzzer += buzzerdelay;
    if(buzzerstate == HIGH){
      buzzerstate =LOW;
    }
    else{
      buzzerstate = HIGH;
    }
    digitalWrite(buzzer,buzzerstate);
  }
if(timeNow - previousTimeled > leddelay){
    previousTimeled += leddelay;
    if(ledstate == HIGH){
      ledstate =LOW;
    }
    else{
      ledstate = HIGH;
    }
    for(int i =0;i<3;i++){
      digitalWrite(LED[i],ledstate);
      digitalWrite(LED[i-2],!ledstate);
      digitalWrite(LED[i-1],!ledstate);
      digitalWrite(LED[i+1],!ledstate);
    }
  }






  
}
}
