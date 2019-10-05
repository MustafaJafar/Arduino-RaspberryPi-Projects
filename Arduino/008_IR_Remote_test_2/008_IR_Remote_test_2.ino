#include <IRremote.h>
#include "IRcode.h"

#define RECV_PIN  3


IRrecv irrecv(RECV_PIN);

decode_results result;
  

void setup (){

  Serial.begin(9600);
  
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
  
  }

void loop  (){
  if (irrecv.decode(&result)) {

    do_something(result.value);//write your code inside the function !
    
    irrecv.resume(); // Receive the next value
  }
  }
  
void do_something(unsigned int value){
 switch(value) {
  case StillPressed : 
    Serial.println("StillPressed");  
    break;
    
  case C_CHm : 
    Serial.println("CH-");  
    break;
  case C_CH : 
    Serial.println("CH");  
    break;
  case C_CHp : 
    Serial.println("CH+");  
    break;    
    
  case C_rewind : 
    Serial.println("<<");  
    break;
  case C_reward : 
    Serial.println(">>");  
    break;    
  case C_PS : 
    Serial.println(">|");  
    break;    
  case C_m : 
    Serial.println("-");  
    break;    
  case C_p : 
    Serial.println("+");  
    break;          
  case C_EQ : 
    Serial.println("EQ");  
    break;   

  case C_0 : 
    Serial.println("0");  
    break;          
  case C_100p : 
    Serial.println("100+");  
    break;          
  case C_200p : 
    Serial.println("200+");  
    break;          
  case C_1 : 
    Serial.println("1");  
    break;          
  case C_2 : 
    Serial.println("2");  
    break;          
  case C_3 : 
    Serial.println("3");  
    break;          
  case C_4 : 
    Serial.println("4");  
    break;          
  case C_5 : 
    Serial.println("5");  
    break;          
  case C_6 : 
    Serial.println("6");  
    break;          
  case C_7 : 
    Serial.println("7");  
    break;          
  case C_8 : 
    Serial.println("8");  
    break;          
  case C_9 : 
    Serial.println("9");  
    break;          

  default:
    Serial.println("Unknown");
  } 
}
  
