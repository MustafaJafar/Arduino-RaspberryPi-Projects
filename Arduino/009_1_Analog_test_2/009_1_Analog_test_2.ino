/*
 * Simple Color Fade up & down
 */
#define r 9
#define g 10
#define b 11


void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  
  for(int dc = 0; dc <= 255 ; dc++ )
  {analogWrite(r, dc);
  delay(10);
  }
for(int dc = 255; dc >= 0 ; dc-- )
  {analogWrite(r, dc);
  delay(10);
  }
}
