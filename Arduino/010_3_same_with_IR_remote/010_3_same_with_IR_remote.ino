/*
 * CH+ : Increase speed 10%
 * CH- : Decrease speed 10%
  */
//Remote 
#include <IRremote.h>
#include "IRcode.h"

#define RECV_PIN  3
IRrecv irrecv(RECV_PIN);
decode_results result;
 
//-------------------------
//Motor Set Speed Variables
#define mf 5
#define mb 6


int dc = 0 ;
int speed = 0 ; //0%
//--------------------------
//Motor Speed Calculation Variables 
#define s1 4

bool value1 = LOW ; 
bool f_flag = LOW ; //first time flag

int counter = 0 ; //how many times you have pressed the button

unsigned long current_time = 0 ; 
unsigned long last_time = 0 ; 
int delta_time = 0 ; 
int T = 1000 ; //1000 millis == 1 second

float RPS = 0 ;//revolution per second  
float RPM = 0 ;//revolution per minute

void setup() {
  // put your setup code here, to run once:
  pinMode(s1, INPUT  );
  Serial.begin(9600);
  
  setup_receiver();
}

void loop() {
  get_remote_and_set_motor_speed();
  
  calculate_motor_Speed();
  
  //motor speed is printed inside calculate_motor_Speed() 
}


void get_remote_and_set_motor_speed(){
  if (irrecv.decode(&result)) { 
      set_motor_speed(result.value);
      
      calculate_dutycycle();  
      set_motor_dutycycle(dc);

      //print_input_speed_dc(); 
      
      irrecv.resume(); // Receive the next value     
     }
     }

void set_motor_speed(unsigned int value){
 switch(value) {
  case StillPressed : 
    //Serial.println("StillPressed");  
    break;
  case C_CHm : 
  Serial.println("CH-");
  if(speed <=0 )
  {Serial.println("Speed is minmum = 0");}
  else {
    Serial.println("Decrease 10%"); 
    speed = speed - 10;
  } 
    break;
  case C_CHp : 
  Serial.println("CH+");
  if (speed >= 100)
    {Serial.println("Speed is maximum = 100");}
    else{
    Serial.println("Increase 10%");  
    speed = speed+10;}
    
    break;
 // default:
    //Serial.println("Unknown");
  } 
}


void setup_receiver(){  
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void calculate_dutycycle(){
  dc = speed * 255 / 100 ;
}

void print_report(){
  print_input_speed_dc();
  print_output_speed_RPM();
  }

void print_input_speed_dc(){
  Serial.print("Set Speed = ");
  Serial.print(speed);
  Serial.println(" %");

  
  Serial.print("Current DC = ");
  Serial.println(dc);

  
}

void set_motor_dutycycle(int s){
  analogWrite(mf,s);
  analogWrite(mb,0);
  }

  
void calculate_motor_Speed (){
  read_and_count();
  
  calculate_delta_time();
  
  if (delta_time >= T){
    calculate_RPM(); 
    
   print_report();
    
    reset_counter_timer();
    }
  }


void read_and_count() {
  value1 = digitalRead(s1);

  if(value1 == LOW)
  { delay(5);//simple debounce 
    if(f_flag == LOW)
    {counter++;
   f_flag = HIGH ;}}
   else {f_flag = LOW ;}
  }

void calculate_delta_time(){
  current_time = millis();//return the number of milliseconds past since the arduino turned on
  delta_time = current_time - last_time ; 
  }

void calculate_RPM(){
  RPS = float(counter) / 20 ; //20 slot per revolution
  RPM = RPS * 60 ; 
  
//  Serial.print("Speed: ");
//  Serial.print(RPS);
//  Serial.println(" RPS");
  }

void print_output_speed_RPM(){
  Serial.print("Speed: ");
  Serial.print(RPM);
  Serial.println(" RPM");

  Serial.println("---------------");
  }

void reset_counter_timer(){
    last_time = current_time;
    counter = 0 ;}
