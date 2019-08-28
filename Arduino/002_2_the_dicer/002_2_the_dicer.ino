#define a 2
#define b 3
#define c 4
#define d 5
#define e 6
#define f 7
#define g 8

long randNumber ;

void setup() {
  // put your setup code here, to run once:
  setup_leds();
  
  //randomSeed(analogRead(0));
  //randNumber = random(1 , 7 ) ;
  //light_number(randNumber);
  light_number(6);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void setup_leds(){
pinMode(a, OUTPUT);
pinMode(b, OUTPUT);
pinMode(c, OUTPUT);
pinMode(d, OUTPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);
}

void light_number (int num){
  switch(num)
 {
  case 0 :
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,0);
   break; 
    
  case 1 :
    digitalWrite(a,0);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);
  break; 

  
  case 2 :
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,0);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,0);
    digitalWrite(g,1);
  break; 

  
  case 3 :
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,1);
  break; 
  
  case 4 :
    digitalWrite(a,0);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,1);
    digitalWrite(g,1);
  break; 

  
  case 5 :
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,0);
    digitalWrite(f,1);
    digitalWrite(g,1);
  break; 
  
  case 6 :
    digitalWrite(a,1);
    digitalWrite(b,0);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
  break; 
    
  case 7 :
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);
  break; 

  
  case 8 :
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,1);
    digitalWrite(f,1);
    digitalWrite(g,1);
  break; 
  
  case 9 :
    digitalWrite(a,1);
    digitalWrite(b,1);
    digitalWrite(c,1);
    digitalWrite(d,1);
    digitalWrite(e,0);
    digitalWrite(f,1);
    digitalWrite(g,1);
  break; 
default :
    digitalWrite(a,0);
    digitalWrite(b,0);
    digitalWrite(c,0);
    digitalWrite(d,0);
    digitalWrite(e,0);
    digitalWrite(f,0);
    digitalWrite(g,0);
  break; 

  }
  
  }
