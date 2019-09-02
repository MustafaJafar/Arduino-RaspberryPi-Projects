//Triangles 

#include "LedControlMS.h"

LedControl lc=LedControl(12,11,10,1);


void setup() {
  
  lc.shutdown(0,false);
  
  lc.setIntensity(0,8);
  
  lc.clearDisplay(0);


int triangle_length = 4; 


//Lower left
int temp = triangle_length ; 
 for (int y = 0 ; y < triangle_length ; y++)
  {
      for(int x = 0 ; x < temp ;x++)
       {
         lc.setLed(0,x,y,true);  
         delay(100);
       }
      temp--;        
  }

//Upper left
temp = triangle_length;
 for (int y = 7 ; y > (7 - triangle_length) ; y--)
  {
      for(int x = 0 ; x < temp ;x++)
       {
         lc.setLed(0,x,y,true);  
         delay(100);
       }   
       temp--;     
  }

//Lower right
 temp = triangle_length;
   for (int y = 0 ; y < triangle_length ; y++)
  {
    for (int x = 7 ; x > (7 - temp) ; x--)
      { lc.setLed(0,x,y,true); 
        delay(100); 
       } 
       temp--;
   }

//Upper right
 temp = triangle_length;
 for (int y = 7 ; y > (7 - triangle_length) ; y--)
  {
    for (int x = 7 ; x > (7 - temp) ; x--)
      { lc.setLed(0,x,y,true);  
        delay(100);
           }   
       temp--;
       }

}
 
    
void loop() {
  // put your main code here, to run repeatedly:

}
