int sw1 =22;

  int sw2 =23;

  int sw3=24;

  int sw4=25;

  int led1 =26;

  int led2 =27;

  int led3 = 28;

  int led4 = 29;

  int led[4]={26,27,28,29};

  

void setup() {

pinMode(26,OUTPUT);

pinMode(27,OUTPUT);

pinMode(28,OUTPUT);

pinMode(29,OUTPUT);

pinMode(22,INPUT);

pinMode(23,INPUT);

pinMode(24,INPUT);

pinMode(25,INPUT);

  

    

 

}

 

void loop() {

 

 

if(digitalRead(sw1)==HIGH){

   int j;

   while(j<3){

    for(int i = 0; i<4; i++){

    digitalWrite(led[i], HIGH);

    delay(500);

    digitalWrite(led[i],LOW);

   if(i>4){

    break;

   }

  }

   j=j+1; // 스위치 1

}

}

if(digitalRead(sw2)==HIGH){

   int j;

   while(j<2){

    for(int i = 4; i>=0; i--){

    digitalWrite(led[i], HIGH);

    delay(500);

    digitalWrite(led[i],LOW);

  }

   j=j+1;

}

}//스위치 2

if(digitalRead(sw3)==HIGH){

   int j;

   while(j<3){

    for(int i = 0; i<4; i++){

    digitalWrite(led[i], HIGH);

    delay(500);

   if(i>4){

    break;

   }

  }

digitalWrite(led1,LOW);

digitalWrite(led2,LOW);

digitalWrite(led3,LOW);

digitalWrite(led4,LOW);

delay(500);

 

   j=j+1; // 스위치 3

}

}

 

if(digitalRead(sw4)==HIGH){

   int j;

   while(j<2){

    for(int i = 4; i>=0; i--){

    digitalWrite(led[i], HIGH);

    delay(500);

    

  }

  digitalWrite(led1,LOW);

digitalWrite(led2,LOW);

digitalWrite(led3,LOW);

digitalWrite(led4,LOW);

delay(500);

   j=j+1;

}

}//스위치 4

 

}
