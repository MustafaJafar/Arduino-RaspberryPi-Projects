#define s1 3

bool value1 = LOW ; 
bool f_flag = LOW ; //first time flag

int counter = 0 ; //how many times you have pressed the button

unsigned long current_time = 0 ; 
unsigned long last_time = 0 ; 
int delta_time = 0 ; 
int T = 1000 ; //1000 millis == 1 second

float RPS = 0 ;//revolution per second  
float RPM = 0 ;//revolution per minute

void setup (){
  pinMode(s1, INPUT  );
  
  Serial.begin(9600);
  delay(5);
  
}


void loop(){ 
  motor_Speed();
}

void motor_Speed (){
  read_and_count();
  
  calculate_delta_time();
  
  if (delta_time >= T){
    calculate_RPM(); 
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
  
  Serial.print("Speed: ");
  Serial.print(RPS);
  Serial.println(" RPS");
 
  Serial.print("Speed: ");
  Serial.print(RPM);
  Serial.println(" RPM");

  Serial.println("---------------");
 
  }


  void reset_counter_timer(){
    last_time = current_time;
    counter = 0 ;}
