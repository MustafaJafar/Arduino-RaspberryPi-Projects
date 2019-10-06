/*
 * CH+ : Next Color 
 * CH- : Last Color
 * 0 to 7 : RGB Colors 
 * EQ : Change Mode "Flaser Mode"
 * --------------------------------------
 * This code is more like the second test 
 * 008_1_IR_Remote_test_2
 */
#include <IRremote.h>
#include "IRcode.h"

#define RECV_PIN  3
IRrecv irrecv(RECV_PIN);
decode_results result;

#define r 4
#define g 5
#define b 6

int color_num = 0 ; 
bool mode = false ; 

String colors[8] = {"None" , "Red", "Green" , "Blue" ,"Yellow" , "Cyan" , "Purple","White" }; 

void setup (){
  Serial.begin(9600);
  setup_RGB();
  setup_receiver();
  }

void loop  (){
  get_remote_and_set_color_num();
  RGB_Control();
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

void get_remote_and_set_color_num(){
  if (irrecv.decode(&result)) { 
      set_color_num(result.value);
      irrecv.resume(); // Receive the next value     
     }
     }
     
void RGB_Control(){
  if (mode == true){
  set_color(colors[color_num]);
  delay(50);
  set_color(colors[0]);
  delay(50);}
  else
  {set_color(colors[color_num]);}
  }

void set_color_num(unsigned int value){
 switch(value) {
  case StillPressed : 
    //Serial.println("StillPressed");  
    break;
  case C_CHm : 
    Serial.println("LastColor"); 
    color_num = (color_num -1+8)%8;
    Serial.println(colors[color_num]);
    break;
  case C_CHp : 
    Serial.println("NextColor");  
    color_num = (color_num+1)%8;
    Serial.println(colors[color_num]);
    break;
    
  case C_EQ : 
    Serial.println("Mode Changed");
    mode = !mode ; 
    break; 
  
  case C_0 : 
    color_num = 0 ;
    Serial.println(colors[0]);
    break;          
             
  case C_1 :
    color_num = 1;
    Serial.println(colors[1]);
    break;          
  case C_2 : 
    color_num = 2 ;
    Serial.println(colors[2]);
    break;          
  case C_3 :
    color_num = 3 ;  
    Serial.println(colors[3]);
    break;          
  case C_4 :   
    color_num = 4 ;
    Serial.println(colors[4]);
    break;          
  case C_5 :
    color_num = 5 ;  
    Serial.println(colors[5]);
    break;          
  case C_6 : 
    color_num = 6 ; 
    Serial.println(colors[6]);
    break;          
  case C_7 : 
    color_num = 7;
    Serial.println(colors[7]); 
    break;          
 // default:
    //Serial.println("Unknown");
  } 
}

void set_color(String color)
{
  if (color == "Red")
      {digitalWrite(r,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(b,LOW);} 
     
  else if(color == "Green")
      {digitalWrite(r,LOW);
      digitalWrite(g,HIGH);
      digitalWrite(b,LOW); 
      }
  else if(color == "Blue")
      {digitalWrite(r,LOW);
      digitalWrite(g,LOW);
      digitalWrite(b,HIGH); 
      }
  else if(color == "Yellow")
      {digitalWrite(r,HIGH);
      digitalWrite(g,HIGH);
      digitalWrite(b,LOW); 
      }
  else if(color == "Cyan")
      {digitalWrite(r,LOW);
      digitalWrite(g,HIGH);
      digitalWrite(b,HIGH); 
      }
  else if(color == "Purple")
      {digitalWrite(r,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(b,HIGH); 
      }
  else if(color == "White")
      {digitalWrite(r,HIGH);
      digitalWrite(g,HIGH);
      digitalWrite(b,HIGH); 
      }
  else {
      digitalWrite(r,LOW);
      digitalWrite(g,LOW);
      digitalWrite(b,LOW);}
  }
