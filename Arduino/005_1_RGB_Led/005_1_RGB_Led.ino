#define r 2
#define g 3
#define b 4

#define b1 5
#define b2 6

bool value1 = HIGH ; 
bool value2 = HIGH ;

int counter = 0 ; 

void setup() {                
  pinMode(r, OUTPUT);     
  pinMode(g, OUTPUT);     
  pinMode(b, OUTPUT);     

  pinMode(b1,INPUT_PULLUP);  
  pinMode(b2,INPUT_PULLUP);
}

void loop() { 

 value1 = digitalRead(b1);
 value2 = digitalRead(b2);
 
 if (value1 == LOW) //Internal Pullup == Active LOW
 {delay(300);//300 millis is almost the time you need to press a button 
 counter= (counter+1)%8;}
 
if (value2 == LOW) 
 {delay(300);
 counter= (counter-1+8)%8;}

 set_color(counter);


/*
for(int i=0;i<8 ; i++)
{set_color(colors[i]);
delay(1000);
}
*/

}

void set_color(int num)
{
  switch(num)
   {
     case 1 : 
      digitalWrite(r,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(b,LOW);
     break;
     case 2 :
      digitalWrite(r,LOW);
      digitalWrite(g,HIGH);
      digitalWrite(b,LOW); 
     break;
     case 3:
      digitalWrite(r,LOW);
      digitalWrite(g,LOW);
      digitalWrite(b,HIGH); 
     break;
     case 4:
      digitalWrite(r,HIGH);
      digitalWrite(g,HIGH);
      digitalWrite(b,LOW); 
     break;
     case 5:
      digitalWrite(r,LOW);
      digitalWrite(g,HIGH);
      digitalWrite(b,HIGH); 
     break;
     case 6:
      digitalWrite(r,HIGH);
      digitalWrite(g,LOW);
      digitalWrite(b,HIGH); 
     break;
     case 7:
      digitalWrite(r,HIGH);
      digitalWrite(g,HIGH);
      digitalWrite(b,HIGH); 
     default :
      digitalWrite(r,LOW);
      digitalWrite(g,LOW);
      digitalWrite(b,LOW);
      }
  }
