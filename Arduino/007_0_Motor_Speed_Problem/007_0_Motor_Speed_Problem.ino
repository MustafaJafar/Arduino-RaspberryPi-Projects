//in this code we are fixing a 
//problem that we will face later

//problem : read the button press one time for each press
//if you are keep pressing the button , the arduino will tell
//if it is the same press or it'w a new press .

#define s1 4

bool value1 = LOW ; 
bool f_flag = LOW ; //first time flag

int counter = 0 ; //how many times you have pressed the button

void setup (){
  pinMode(s1, INPUT_PULLUP);
  
  Serial.begin(9600);
  delay(5);
  
  Serial.print("Button pressed: ");
  Serial.print(counter);
  Serial.println(" times");
}


void loop(){ 
  //the arduino will not increament untill you stop pressing the button
  //so it will only increament at the first time it reads the button HIGH
  //and will do any thing untill you stop pressing and again ...

  //we solved the same problem by delay so that the arduino
  //waits the needed time that human need for making one press

  //but if the presses aren't made by human then this solution 
  //won't be valid !
  
  value1 = digitalRead(s1);
  
  if(value1 == LOW )
  { 
    //delay(5);//simple debounce!
    counter++;
    Serial.print("Button pressed: ");
    Serial.print(counter);
    Serial.println(" times");}
    }
  


