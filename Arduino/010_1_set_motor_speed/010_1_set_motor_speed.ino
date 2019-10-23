#define mb 5
#define mf 6

int dc = 128 ;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.print("Current DC = ");
  Serial.println(dc);
set_forward_speed(dc);

}

void loop() {
  // put your main code here, to run repeatedly:

}


void set_forward_speed(int s){
  analogWrite(mf,s);
  analogWrite(mb,0);
  }
