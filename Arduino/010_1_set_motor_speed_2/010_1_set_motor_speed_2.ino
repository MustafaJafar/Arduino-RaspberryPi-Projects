//-------------------------
//Motor Set Speed Variables
#define mf 5
#define mb 6

int dc = 0 ;
int speed = 80 ; //0%

void setup() {
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
}


void calculate_dutycycle(){
  //dc = speed * 255 / 100 ;
  dc =  map(speed, 0, 100, 0, 255);
  dc = constrain(dc, 0, 255);
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
