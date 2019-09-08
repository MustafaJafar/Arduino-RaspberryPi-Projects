#define led  13

//at 1 millisscond our eyes don't catch what really happens  !
//total time we had waited = 1 + 1 = 2 millseconds 
//so we will play within that range ;) 
// 2 millseconds => 2000 microseconds (for easier calculations))

int Ttotal = 2000 ; //Ton + Toff
int Ton = 0 ; 
int Toff = 0;

 
void setup() {                
  pinMode(led, OUTPUT); 
  Ton = 500 ; //Ton/Ttotal = 25% (1/4 intensity)
              //Ton/Ttotal == dutycycle 
  Toff = Ttotal - Ton ; //Toff is the rest (3/4 in this case)
}

void loop() {
  digitalWrite(led, HIGH); 
  delayMicroseconds(Ton);      
  digitalWrite(led, LOW);  
  delayMicroseconds(Toff);      
}

