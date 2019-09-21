#define m1 2
#define m2 3 

void setup() {
  motor_setup();
  motor_CW();
  delay(5000);
  motor_CCW();
  delay(5000);
  motor_stop();
  }


void loop() {
  // put your main code here, to run repeatedly:

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

void motor_stop(){
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
}

  
