//Checker board 

#include "LedControlMS.h"

LedControl lc=LedControl(12,11,10,1);

bool flag = true ;

void setup() {
  
  lc.shutdown(0,false);
  
  lc.setIntensity(0,3);
  
  lc.clearDisplay(0);

for(int x = 0 ; x < 8 ;x++)
  {
    for (int y = 0 ; y <8 ;y++)
     {
       
      lc.setLed(0,x,y,flag);  
      delay(1);
      if (y != 7)
      {flag = !flag ;}
     
     }
   }

}

void loop() {
  // put your main code here, to run repeatedly:

/*
  flag = !flag ;
  
  for(int x = 0 ; x < 8 ;x++)
  {
    for (int y = 0 ; y <8 ;y++)
     {
       
      lc.setLed(0,x,y,flag);  
      delay(1);
      if (y != 7)
      {flag = !flag ;}
     
     }
   }
*/
}
