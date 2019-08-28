#define one 2
#define two 3
#define three 4
#define four 5
#define five 6
#define six 7

int numbers[6] = {one , two , three ,four , five , six};
long randNumber ;

void setup() {
  setup_leds();
  
  randomSeed(analogRead(0));
  randNumber = random(1 , 7 ) ;
  light_number(randNumber);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void setup_leds(){
for(int i = 0 ; i < 6 ; i++)
{ pinMode(numbers[i], OUTPUT); }
}

void light_number (int num){
  for(int i = 0 ; i < num ; i++)
{ digitalWrite(numbers[i], HIGH); }
  
  }
