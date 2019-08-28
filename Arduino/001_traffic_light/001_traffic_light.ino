#define red 4
#define yellow 5
#define green 6


void setup() {
  // put your setup code here, to run once:
  setup_leds();
}

void loop() {
  // put your main code here, to run repeatedly:
  blink_led(red ,6000);
  blink_led(yellow , 2000);
  blink_led(green , 6000);
}

void setup_leds(){
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  }

void blink_led(int led , int timer){
 digitalWrite(led, HIGH);
 delay (timer);
 digitalWrite(led, LOW);
 delay (1000);
  }
