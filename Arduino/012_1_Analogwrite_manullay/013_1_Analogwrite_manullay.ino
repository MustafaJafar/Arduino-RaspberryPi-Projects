#define led  13

int timer = 1 ; //1000,500,50,1

//at 1 millisscond our eyes don't catch what really happens  !
//total time we had waited = 1 + 1 = 2 millseconds  

void setup() {                
  pinMode(led, OUTPUT);     
}

void loop() {
  digitalWrite(led, HIGH);   
  delay(timer);  //1 millsecond
  digitalWrite(led, LOW);    
  delay(timer);  //another 1 millsecond 
}
