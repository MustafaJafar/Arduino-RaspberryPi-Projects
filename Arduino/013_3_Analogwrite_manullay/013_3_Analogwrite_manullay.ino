#define led  13

//at 1 millisscond our eyes don't catch what really happens  !
//total time we had waited = 1 + 1 = 2 millseconds 
//so we will play within that range ;) 
// 2 millseconds => 2000 microseconds (for easier calculations))

int Ttotal = 2000 ; //Ton + Toff
int Ton = 0 ; 
int Toff = 0;

float dc = 100 ; //duty cycle = Ton/Ttotal
                 //Ton = duty cycle * Ttotal / 100
  
 
void setup() {                
  pinMode(led, OUTPUT);      
  //calculate_prams_easy(500);//Ton 
  //calculate_prams_advanced(10); //DC
}

void loop() { 
 //set_intensity();
  light_dimmer();//change dc automatically
}


//------------------------------------------
void calculate_prams_easy(int t) {
    Ton = t ; 
    Toff = Ttotal - Ton ;
  }

void calculate_prams_advanced(int d) {
    dc = d ;
    Ton = int((dc * Ttotal) / 100) ; 
    Toff = Ttotal - Ton ;
  }

void set_intensity(){
  digitalWrite(led, HIGH); 
  delayMicroseconds(Ton);      
  digitalWrite(led, LOW);  
  delayMicroseconds(Toff); 
  }

void light_dimmer(){
  for (int i = 0 ; i < 101 ; i++)
  {
    calculate_prams_advanced(i); 
    digitalWrite(led, HIGH); 
    delayMicroseconds(Ton);      
    digitalWrite(led, LOW);  
    delayMicroseconds(Toff); 
    delay(10);     
  }
for (int i = 100 ; i > 0 ; i--)
  {
    calculate_prams_advanced(i); 
    digitalWrite(led, HIGH); 
    delayMicroseconds(Ton);      
    digitalWrite(led, LOW);  
    delayMicroseconds(Toff); 
    delay(10);     
  }
}

