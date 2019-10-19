/*
 * The Same Color Fade without using a for loop
 * so that we can change colors without affecting 
 * "The fade Program"
 * we used "void loop" properties instead of "for loop"
 */
#define r 9
#define g 10
#define b 11

int dc = 0 ;
bool dc_flag=true;

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  set_dutycycle();
  
  analogWrite(r, dc);
  delay(10);
}

void set_dutycycle(){
  if(dc==255)
    dc_flag = false;
  else if (dc == 0)
    dc_flag = true; 
    
  if(dc_flag)
  dc = (dc+1)%256;
  else
  dc = (dc-1)%256;
  }
