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

    Serial.println(return_button(result.value));
    //Continue your code here
    
    irrecv.resume(); // Receive the next value
  }
  }
  
String return_button(unsigned int value){
 switch(value) {
  case StillPressed : 
    return "StillPressed";  
    break;
    
  case C_CHm : 
    return "CH-";  
    break;
  case C_CH : 
    return "CH";  
    break;
  case C_CHp : 
    return "CH+";  
    break;    
    
  case C_rewind : 
    return "<<";  
    break;
  case C_reward : 
    return">>";  
    break;    
  case C_PS : 
    return ">|";  
    break;    
  case C_m : 
    return "-";  
    break;    
  case C_p : 
    return "+";  
    break;          
  case C_EQ : 
    return "EQ";  
    break;   

  case C_0 : 
    return "0";  
    break;          
  case C_100p : 
    return "100+";  
    break;          
  case C_200p : 
    return "200+";  
    break;          
  case C_1 : 
    return "1";  
    break;          
  case C_2 : 
    return "2";  
    break;          
  case C_3 : 
    return "3";  
    break;          
  case C_4 : 
    return "4";  
    break;          
  case C_5 : 
    return "5";  
    break;          
  case C_6 : 
    return "6";  
    break;          
  case C_7 : 
    return "7";  
    break;          
  case C_8 : 
    return "8";  
    break;          
  case C_9 : 
    return "9";  
    break;          

  default:
    return "Unknown";
  } 
}
  