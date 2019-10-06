#include <IRremote.h>
#include "IRcode.h"

#define RECV_PIN  3
IRrecv irrecv(RECV_PIN);
decode_results result;

#define r 4
#define g 5
#define b 6

int counter = 0 ; 
unsigned int colors[8] = {C_0 , C_1,C_2,C_3,C_4,C_5,C_6,C_7};
unsigned int last_result = 0 ;
unsigned int last_result_2 = 0 ; 

bool mode = false ; 

void setup (){

  Serial.begin(9600);
  setup_RGB();
  setup_receiver();
  
  }

void loop  (){
  if (irrecv.decode(&result)) { 
      last_result = result.value ;
      irrecv.resume(); // Receive the next value     
     }
  if (mode == true){
  set_color(last_result);
  delay(50);
  set_color(C_0);
  delay(50);}
  else
  {set_color(last_result);}
}
void setup_RGB(){
     
  pinMode(r, OUTPUT);     
  pinMode(g, OUTPUT);     
  pinMode(b, OUTPUT);     

}

void setup_receiver(){  
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void set_color(unsigned int value){
 switch(value) {
  case StillPressed : 
    //Serial.println("StillPressed");  
    break;
  case C_CHm : 
    Serial.println("NextColor"); 
    counter= (counter-1+8)%8;
    set_color(colors[counter]);
    last_result = colors[counter] ; 
    break;
  case C_CHp : 
    Serial.println("LastColor");  
    counter= (counter+1)%8;
    set_color(colors[counter]);
    last_result = colors[counter] ;
    break;
        
  case C_0 : 
    Serial.println("None");
    digitalWrite(r,LOW);
    digitalWrite(g,LOW);
    digitalWrite(b,LOW);
    if (mode == false)  
    {last_result = C_0 ;
    counter = 0 ;}
    break;          
  case C_EQ : 
    Serial.println("Mode Changed");
    mode = !mode ; 
    last_result = colors[counter] ;
    break; 
             
  case C_1 : 
    Serial.println("RED");  
    digitalWrite(r,HIGH);
    digitalWrite(g,LOW);
    digitalWrite(b,LOW);
    last_result = C_1 ;
    counter = 1;
    break;          
  case C_2 : 
    Serial.println("Green");  
    digitalWrite(r,LOW);
    digitalWrite(g,HIGH);
    digitalWrite(b,LOW);
    last_result = C_2 ;
    counter = 2 ;
    break;          
  case C_3 : 
    Serial.println("Blue"); 
    digitalWrite(r,LOW);
    digitalWrite(g,LOW);
    digitalWrite(b,HIGH);
    last_result = C_3 ;
    counter = 3 ;  
    break;          
  case C_4 : 
    Serial.println("Yellow");  
    digitalWrite(r,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(b,LOW);
    last_result = C_4 ;
    counter = 4 ;
    break;          
  case C_5 : 
    Serial.println("Cyan");
    digitalWrite(r,LOW);
    digitalWrite(g,HIGH);
    digitalWrite(b,HIGH);
    last_result = C_5 ;
    counter = 5 ;  
    break;          
  case C_6 : 
    Serial.println("Purle");
    digitalWrite(r,HIGH);
    digitalWrite(g,LOW);
    digitalWrite(b,HIGH);
    last_result = C_6 ; 
    counter = 6 ; 
    break;          
  case C_7 : 
    Serial.println("White"); 
    digitalWrite(r,HIGH);
    digitalWrite(g,HIGH);
    digitalWrite(b,HIGH);
    last_result = C_7 ;
    counter = 7; 
    break;          
 // default:
    //Serial.println("Unknown");
  } 
}
  
