/*  
 * Note that : 
 *  ST = T  => for each 1 control signal 1 error readings 
 */
//-------------------------
//Sampling Time Variables
const int ST = 500 ; //Sample Time = 500 millis == 0.5 second 

int DST = 0 ; //Delta Sample Time
unsigned long CST = 0 ; //Current Sample Time 
unsigned long LST = 0 ; // Last Sample Time 

double C_OUT = 0 ;//Current Measuerd output

//int STC = 0 ; //Sample Timer Counter : used to count number of sample times 
              //as Control Signal will be calculated
              //after 10 Sample Times 
              
//-------------------------
//PID control Variables 
int CS = 0 ; //Control Signal == Duty Cycle "PWM value"
double Sp = 0 ; //Set Point => RPM
double Kp = 0 ; //proportional gain
double Ki = 0 ; //Integral Gain
double Kd = 0 ; //Derivative Gain

double error = 0 ; 
double total_error = 0 ;
double delta_error = 0 ; 
double last_error = 0 ; 

int Min_CS = 80 ; //Min Control Signal
int Max_CS = 255 ; //Max Control Signal

//--------------------
 
void setup() {

//I have sat these parameters in Setup loop to simulate  
  //1)User may change set point according to his prefrence
  //2)Gains can be changed automatically as user may use an auto tuner program
  Sp = 60 ; 
  Kp = 3.5 ;
  Ki = 3 ; 
  Kd = 0.3 ;
  
}

void loop() {
  PID_Control();
}

void PID_Control(){
  
  CST = millis();  
  DST = CST - LST ;
   
  if (DST >= ST ){
    //calculate error 
    
    //C_OUT = measure_output() ; 
    error = Sp - C_OUT ;
    delta_error = error - last_error ;
    total_error += error ; 
    total_error = constrain(total_error, Min_CS, Max_CS);
     
    CS = Kp*error + Ki*total_error + Kd*delta_error ;
    CS = constrain(CS, Min_CS, Max_CS);
     
    //apply_control_signal(); 

    //Reset Control Loop
    LST = CST; 
    last_error = error ; 
      }
   }
