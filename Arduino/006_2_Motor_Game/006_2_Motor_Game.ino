//using l9110s motor driver 

#define m1 2
#define m2 3 

#define s1 5
#define s2 6

bool value1 = HIGH ; 
bool value2 = HIGH ;

void setup() {
  motor_setup();
  sensors_setup();
  //motor_CW();
  //delay(5000);
  //motor_CCW();
  //delay(5000);
  //motor_stop();
  }


void loop() {
  // put your main code here, to run repeatedly:
 value1 = digitalRead(s1);//line tracking sensor (as touch sensor)
 value2 = digitalRead(s2);//this sensor is Active LOW
 
 if (value1 == LOW && value2 == HIGH){motor_CW();} 
 else if (value1 == HIGH && value2 == LOW ){motor_CCW();}
 else {motor_stop();}
}


void sensors_setup(){
  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  }

void motor_setup(){
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  }
void motor_CCW(){
  digitalWrite(m1, HIGH);
  digitalWrite(m2, LOW);
  }

  
void motor_CW(){
  digitalWrite(m2, HIGH);
  digitalWrite(m1, LOW);
  }
  
void motor_stop(){
   digitalWrite(m1, LOW);
   digitalWrite(m2, LOW);
  }
  
