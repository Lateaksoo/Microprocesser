#include<avr/io.h>

#include<util/delay.h>

int seg[10]={0b01011111,0b00000110,0b00111011,0b00101111,0b01100110,0b01101101,0b01111101,0b01000111,0b01111111,0b01100111};

int led[10]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};

int i=0;

 

int state=0;

 

void setup() {

 PORTC=0xFF; //스위치 입력

 DDRC=0x00;

 

 PORTA=0x00;//7세그먼트 출력

 DDRA=0xFF;

 

 PORTB=0x00;//LED 출력

 DDRB=0xFF;

}

 

void loop() {

  

  if((PINC & 0x01)==0x01){

    state++;

    if(state==3){

      state=0;

    }

    delay(100);

  }

 

switch(state){

  

  case 0 :

          PORTB=0x00;

          PORTA=0b01011111;

          

  

          break;

 

  case 1 :for(int i=0; i<10;i++){

    if((PINC & 0x01)==0x01){

        break;  

         }

         PORTA=seg[i];

         PORTB=led[i];

    

         

         delay(500);

         if(i==9){

           i=-1;

             }

         }

        break;

        

     case 2:

             break;   

}

}
