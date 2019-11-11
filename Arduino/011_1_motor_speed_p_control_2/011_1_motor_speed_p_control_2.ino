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

const int ST = 500 ; //Sample Time = 100 millis == 0.1 second
int DST = 0 ; //Delta Sample Time
unsigned long CST = 0 ; //Current Sample Time 
unsigned long LST = 0 ; // Last Sample Time 

float C_RPM = 0 ;//Current Revolution Per Minute

//int STC = 0 ; //Sample Timer Counter : used to count number of sample times 

//-------------------------
//P control Variables 
int CS = 0 ; //Control Signal == Duty Cycle "PWM value"
double Sp = 0 ; //Set Point => RPM
double Kp = 0 ; //proportional gain
double error = 0 ; 

int Min_CS = 80 ; //Min Control Signal
int Max_CS = 255 ; //Max Control Signal

//--------------------
 
void setup() {
  pinMode(S1, INPUT);
  
  Serial.begin(9600);

  Sp = 60 ; //60 RPM 
  Kp = 6.5 ; 
  
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
    C_RPM = counter * 6 ; //revolution per 0.5 second = number of slots / 20 
                    //revolution per 60 second = (counter of 0.5 / 20)* 2 * 60 = c*2*60/20 = c*6                      
   
    error = Sp - C_RPM ;  
    
    CS = error * Kp ;
    CS = constrain(CS, Min_CS, Max_CS);
     
    print_report(); //C_RPM , error , CS 

    //Apply Control Signal
    analogWrite(mf,CS); 
    analogWrite(mb,0);
      
    //Reset Loop
    LST = CST; 
    counter = 0 ;
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
    Serial.println(C_RPM);//only print to use serial plot 
    //Serial.print ("Error= ");
    //Serial.println(error);
    //Serial.print ("Control Signal= ");
    //Serial.println(CS);
    //Serial.println("---------------");

  }
