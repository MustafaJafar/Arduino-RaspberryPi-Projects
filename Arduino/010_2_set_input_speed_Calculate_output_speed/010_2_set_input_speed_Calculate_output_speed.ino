//-------------------------
//Motor Set Speed Variables
#define mf 5
#define mb 6

int dc = 0 ;
int speed = 80 ; //0%
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

  //Initiale Value
  calculate_dutycycle();  
  print_input_speed_dc();
  
  set_motor_dutycycle(dc);
}

void loop() {

if(Serial.available() > 0)
  {speed = Serial.parseInt();
  
  calculate_dutycycle();  
  print_input_speed_dc();
  
  set_motor_dutycycle(dc);}
  
  calculate_motor_Speed();//RPM is printed inside calculate_motor_Speed()
}


void calculate_dutycycle(){
  //dc = speed * 255 / 100 ;
  dc =  map(speed, 0, 100, 0, 255);
  dc = constrain(dc, 0, 255);
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
  
  Serial.println("---------------");
  
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
    
    //print_report();
    print_output_speed_RPM();  
    
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
