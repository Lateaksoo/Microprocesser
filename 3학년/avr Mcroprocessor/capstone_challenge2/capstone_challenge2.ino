int led[4] = {26,27,28,29};

 

void setup() {

  pinMode(26,OUTPUT);

 pinMode(27,OUTPUT);

  pinMode(28,OUTPUT);

   pinMode(29,OUTPUT);

   

  

}

 

void loop() {

  for(int i = 0; i<4 ; i++){

    digitalWrite(led[i], HIGH);

    delay(500);

    digitalWrite(led[i],LOW);

  }

    

 

}
