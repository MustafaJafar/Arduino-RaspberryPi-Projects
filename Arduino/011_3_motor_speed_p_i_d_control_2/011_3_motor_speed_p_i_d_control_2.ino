/*  
 * Note that : 
 *  ST = T  => for each 1 control signal 1 error readings 
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

//-------------------------
//P control Variables 
int CS = 0 ; //Control Signal == Duty Cycle "PWM value"
double Sp = 0 ; //Set Point => RPM
double Kp = 0 ; //proportional gain
double Ki = 0 ; //Integral Gain
double Kd = 0 ; //Derivative Gain

double error = 0 ; 
double total_error = 0 ;
double delta_error = 0 ; 
double last_error = 0 ;

//int STC = 0 ; //Sample Timer Counter : used to count number of sample times 

int Min_CS = 80 ; //Min Control Signal
int Max_CS = 255 ; //Max Control Signal

//--------------------
 
void setup() {
  pinMode(S1, INPUT);
  
  Serial.begin(9600);


  Sp = 60 ; //60 RPM 
  Kp = 3.5 ;
  Ki = 3 ; 
  Kd = 0.1 ;
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
    
    error = Sp - C_RPM ;
    delta_error = error - last_error ;
    total_error += error ; 
    total_error = constrain(total_error, Min_CS, Max_CS);
      
    CS = error * Kp + total_error * Ki+ delta_error*Kd ;
    CS = constrain(CS, Min_CS, Max_CS);
     
    print_report(); //C_RPM , error , CS 

    //Apply Control Signal
    analogWrite(mf,CS); 
    analogWrite(mb,0);
      
      
    //Reset Loop
    LST = CST; 
    counter = 0 ;
    last_error = error ;     
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
    //Serial.print ("Current RPM= ");
    Serial.println(C_RPM);
    //Serial.print ("Error= ");
    //Serial.println(error);
    //Serial.print ("Control Signal= ");
    //Serial.println(CS);
    //Serial.println("---------------");

  }
