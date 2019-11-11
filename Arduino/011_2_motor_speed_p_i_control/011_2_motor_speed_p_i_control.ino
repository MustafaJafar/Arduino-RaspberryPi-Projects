/*
 * Using one counter for both sampling and control signal 
 *  as control loop time is 10 times sampling time  
 *  i.e. control signal is calulated after 10 sample times 
 *  
 * Note that : 
 *  ST = T/10 => for each 1 control signal 10 error readings 
 *  for proportional control we only use the last error reading => current for controller          
 *  but for other controlers they use all the 10 errors readings 
 */
//-------------------------
//Motor Set Speed Variables
#define mf 5
#define mb 6

//-------------------------
//Motor Speed Calculation Variables 
#define S1 4

bool value1 = LOW ; 
bool f_flag = LOW ; //first time flag

float counter = 0 ; //how many slots had arduino read ?

const int ST = 500 ; //Sample Time = 500 millis == 0.5 second
int DST = 0 ; //Delta Sample Time
unsigned long CST = 0 ; //Current Sample Time 
unsigned long LST = 0 ; // Last Sample Time 

float C_RPM = 0 ;//Current Revolution Per Minute
float avg_RPM = 0 ;
//-------------------------
//P control Variables 
int CS = 0 ; //Control Signal == Duty Cycle "PWM value"
double Sp = 0 ; //Set Point => RPM
double Kp = 0 ; //proportional gain
double Ki = 0 ; //Integral Gain

double error = 0 ; 
double avg_error = 0 ;
double total_error = 0 ;

int STC = 0 ; //Sample Timer Counter : used to count number of sample times 

int Min_CS = 80 ; //Min Control Signal
int Max_CS = 255 ; //Max Control Signal

//--------------------
 
void setup() {
  pinMode(S1, INPUT);
  
  Serial.begin(9600);


  Sp = 60 ; //60 RPM 
  Kp = 3.5 ;
  Ki = 3 ; 
  
}

void loop() {
  PID_Control();
}

void PID_Control(){
  CST = millis();  
  DST = CST - LST ;
   
  count_pulses(); //used for reading motor speed
  
  if (DST >= ST ){
    //calculate error 
    C_RPM = counter * 6 ; 
    avg_RPM += C_RPM ;
    
    error = Sp - C_RPM ;
    total_error += error ; 
    
    LST = CST; 
    counter = 0 ;
    STC++ ; 
       
    if (STC >= 9 ){//Control Signal will only be calculated after 10 sampel times ! 
      
      avg_RPM /= 10 ;
      avg_error = Sp - avg_RPM ;

      total_error = constrain(total_error, Min_CS, Max_CS);
      
      CS = avg_error * Kp + total_error * Ki ;
      CS = constrain(CS, Min_CS, Max_CS);
     
      print_report(); //C_RPM , error , CS 
 
      analogWrite(mf,CS); 
      analogWrite(mb,0);
      
      STC = 0 ;
      avg_RPM = 0 ;
      }
   }
}


void count_pulses(){
  value1 = digitalRead(S1);

  if(value1 == LOW)
  { delay(1);//simple debounce
    if(f_flag == LOW)
    {counter++;
     f_flag = HIGH ;}}
   else {f_flag = LOW ;}
  }

void print_report() {
    //Serial.print ("Average RPM= ");
    Serial.println(avg_RPM);
    //Serial.print ("Average Error= ");
    //Serial.println(avg_error);
    //Serial.print ("Control Signal= ");
    //Serial.println(CS);
    //Serial.println("---------------");

  }
