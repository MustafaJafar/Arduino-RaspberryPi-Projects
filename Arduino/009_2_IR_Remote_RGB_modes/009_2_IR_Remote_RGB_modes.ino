/*
 * CH+ : Next Color 
 * CH- : Last Color
 * 0 to 7 : RGB Colors 
 * EQ : Change Mode "Solid Color - Flaser Mode - Fade Mode"
 * --------------------------------------
 * This code is an update for
 * 008_2_IR_Remote_RGB_modes
 */
#include <IRremote.h>
#include "IRcode.h"

#define RECV_PIN  3
IRrecv irrecv(RECV_PIN);
decode_results result;

#define r 9
#define g 10
#define b 5  //for some reason
             //bin 11 didn't work in mode 3  

int color_num = 0 ; 
int mode = 0   ; 

String colors[8] = {"None" , "Red", "Green" , "Blue" ,"Yellow" , "Cyan" , "Purple","White" }; 

int dc = 0 ;
bool dc_flag=true;

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
      select_color(result.value);
      irrecv.resume(); // Receive the next value     
     }
    }
     
void RGB_Control(){
  switch(mode){
  case 0 : 
    set_color_digital(colors[color_num]);
  break ; 
  case 1 :    
    set_color_digital(colors[color_num]);
    delay(50);
    set_color_digital(colors[0]);
    delay(50);
  break ; 
  case 2 : 
    set_dutycycle();
    set_color_analog(colors[color_num]);
    delay(10);
  break;
  }
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

void select_color(unsigned int value){
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
    mode = (mode + 1)%3 ; 
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


void set_color_digital(String color)
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

void set_color_analog(String color)
{
  if (color == "Red")
      {analogWrite(r,dc);
      analogWrite(g,0);
      analogWrite(b,0);} 
     
  else if(color == "Green")
      {analogWrite(r,0);
      analogWrite(g,dc);
      analogWrite(b,0); 
      }
  else if(color == "Blue")
      {analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,dc); 
      }
  else if(color == "Yellow")
      {analogWrite(r,dc);
      analogWrite(g,dc);
      analogWrite(b,0); 
      }
  else if(color == "Cyan")
      {analogWrite(r,0);
      analogWrite(g,dc);
      analogWrite(b,dc); 
      }
  else if(color == "Purple")
      {analogWrite(r,dc);
      analogWrite(g,0);
      analogWrite(b,dc); 
      }
  else if(color == "White")
      {analogWrite(r,dc);
      analogWrite(g,dc);
      analogWrite(b,dc); 
      }
  else {
      analogWrite(r,0);
      analogWrite(g,0);
      analogWrite(b,0);}
  }
