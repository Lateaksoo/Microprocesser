
#include <LiquidCrystal.h>
LiquidCrystal lcd(22, 23, 24, 25, 26, 27);

String line1string = "KOREA Fighting!";
String line2string = "Induk University!";

int L =17;
int LL =1;
int R = -1;
int RR = -1;

void setup()
{
    lcd.begin(16, 2);  
}
 
void loop() {
    //첫 행에 출력될 문자의 길이 저장
    int len1=line1string.length();
    lcd.setCursor(0,0);
    
    //두번째 행에 출력될 문자의 길이 저장
    int len2 = line2string.length();
    lcd.setCursor(0,1);


        String line1stringplus = "                "+line1string+"                ";
        String temp1;
        temp1=line1stringplus.substring(L,LL);
        L++;
        LL++;
        if(L>line1stringplus.length()){
          L=16;
          LL=0;
        }
        lcd.print(temp1);



        String line2stringplus = "                "+line2string+"                ";
        String temp2;
        if(RR<1){
          R=line2stringplus.length();
          RR=R-16;
        }
        temp2=line2stringplus.substring(R,RR);
        R--;
        RR--;
        lcd.print(temp2);
        
        
        
        for(int i = 0; i <=15; i++)
        {
            lcd.setCursor(0,0);
            lcd.print(temp1);
            lcd.setCursor(0,1);
            lcd.print(temp2);
            delay(10);
        }
    
}
