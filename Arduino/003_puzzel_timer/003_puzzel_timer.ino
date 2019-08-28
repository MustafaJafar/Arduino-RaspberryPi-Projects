#define a1 2
#define b1 3
#define c1 4
#define d1 5
#define e1 6
#define f1 7
#define g1 8

#define a2 9
#define b2 10
#define c2 11
#define d2 12
#define e2 13
#define f2 14
#define g2 15

#define buzz 16

int segments[2][7] = { {a1 , b1 , c1 , d1 , e1 , f1 , g1} , {a2 , b2 , c2 , d2 ,e2 , f2 , g2}  }; 

void setup() {
  // put your setup code here, to run once:
  setup_leds();
  setup_buzz();
  
for (int i = 0 ; i < 10 ; i++ )
 {
  light_number(2,i);
  for (int j = 0 ; j<10;j++){   
  light_number(1,j);
  delay(100);
  }
}

  buzzer(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void setup_buzz(){
  pinMode(buzz, OUTPUT);
  }

void buzzer(int timer)
{
   digitalWrite(buzz , HIGH);
  delay(timer);
  digitalWrite(buzz,LOW);
  delay(10);
  }



void setup_leds()
{
 for (int i = 0 ; i < 2 ; i++)
   {
    for (int j = 0 ; j < 7 ; j++)
    {
      pinMode(segments[i][j], OUTPUT);
    }
 }
}

void light_number (int seg , int num){
  switch(num)
 {
  case 0 :
    digitalWrite(segments[seg-1][0],1);
    digitalWrite(segments[seg-1][1],1);
    digitalWrite(segments[seg-1][2],1);
    digitalWrite(segments[seg-1][3],1);
    digitalWrite(segments[seg-1][4],1);
    digitalWrite(segments[seg-1][5],1);
    digitalWrite(segments[seg-1][6],0);
   break; 
    
  case 1 :
    digitalWrite(segments[seg-1][0],0);
    digitalWrite(segments[seg-1][1],1);
    digitalWrite(segments[seg-1][2],1);
    digitalWrite(segments[seg-1][3],0);
    digitalWrite(segments[seg-1][4],0);
    digitalWrite(segments[seg-1][5],0);
    digitalWrite(segments[seg-1][6],0);
  break; 

  
  case 2 :
    digitalWrite(segments[seg-1][0],1);
    digitalWrite(segments[seg-1][1],1);
    digitalWrite(segments[seg-1][2],0);
    digitalWrite(segments[seg-1][3],1);
    digitalWrite(segments[seg-1][4],1);
    digitalWrite(segments[seg-1][5],0);
    digitalWrite(segments[seg-1][6],1);
  break; 

  
  case 3 :
    digitalWrite(segments[seg-1][0],1);
    digitalWrite(segments[seg-1][1],1);
    digitalWrite(segments[seg-1][2],1);
    digitalWrite(segments[seg-1][3],1);
    digitalWrite(segments[seg-1][4],0);
    digitalWrite(segments[seg-1][5],0);
    digitalWrite(segments[seg-1][6],1);
  break; 
  
  case 4 :
    digitalWrite(segments[seg-1][0],0);
    digitalWrite(segments[seg-1][1],1);
    digitalWrite(segments[seg-1][2],1);
    digitalWrite(segments[seg-1][3],0);
    digitalWrite(segments[seg-1][4],0);
    digitalWrite(segments[seg-1][5],1);
    digitalWrite(segments[seg-1][6],1);
  break; 

  
  case 5 :
    digitalWrite(segments[seg-1][0],1);
    digitalWrite(segments[seg-1][1],0);
    digitalWrite(segments[seg-1][2],1);
    digitalWrite(segments[seg-1][3],1);
    digitalWrite(segments[seg-1][4],0);
    digitalWrite(segments[seg-1][5],1);
    digitalWrite(segments[seg-1][6],1);
  break; 
  
  case 6 :
    digitalWrite(segments[seg-1][0],1);
    digitalWrite(segments[seg-1][1],0);
    digitalWrite(segments[seg-1][2],1);
    digitalWrite(segments[seg-1][3],1);
    digitalWrite(segments[seg-1][4],1);
    digitalWrite(segments[seg-1][5],1);
    digitalWrite(segments[seg-1][6],1);
  break; 
    
  case 7 :
    digitalWrite(segments[seg-1][0],1);
    digitalWrite(segments[seg-1][1],1);
    digitalWrite(segments[seg-1][2],1);
    digitalWrite(segments[seg-1][3],0);
    digitalWrite(segments[seg-1][4],0);
    digitalWrite(segments[seg-1][5],0);
    digitalWrite(segments[seg-1][6],0);
  break; 

  
  case 8 :
    digitalWrite(segments[seg-1][0],1);
    digitalWrite(segments[seg-1][1],1);
    digitalWrite(segments[seg-1][2],1);
    digitalWrite(segments[seg-1][3],1);
    digitalWrite(segments[seg-1][4],1);
    digitalWrite(segments[seg-1][5],1);
    digitalWrite(segments[seg-1][6],1);
  break; 
  
  case 9 :
    digitalWrite(segments[seg-1][0],1);
    digitalWrite(segments[seg-1][1],1);
    digitalWrite(segments[seg-1][2],1);
    digitalWrite(segments[seg-1][3],1);
    digitalWrite(segments[seg-1][4],0);
    digitalWrite(segments[seg-1][5],1);
    digitalWrite(segments[seg-1][6],1);
  break; 
default :
    digitalWrite(segments[seg-1][0],0);
    digitalWrite(segments[seg-1][1],0);
    digitalWrite(segments[seg-1][2],0);
    digitalWrite(segments[seg-1][3],0);
    digitalWrite(segments[seg-1][4],0);
    digitalWrite(segments[seg-1][5],0);
    digitalWrite(segments[seg-1][6],0);
  break; 

  }
  
  }
