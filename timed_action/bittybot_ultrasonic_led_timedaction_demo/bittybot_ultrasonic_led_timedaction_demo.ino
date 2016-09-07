#include "BittyBot2.h"
#include <NewPing.h>
#include <TimedAction.h>

int leftspeed = 175;
int rightspeed = 175;

BittyBot bot(44,46,36,38,40,42); //Left Enable, Right Enable, Pin1 for Left, Pin2 for Left, Pin 1 for Right, Pin 2 for Right

#define TRIGGER_PIN 5 //Arduino Pin Tied to Trigger Pin on the ultrasonic sensor
#define ECHO_PIN 6 //Arduino Pin Tied to echo pin on the ultrasonic sensor
#define MAX_DISTANCE 500 //Maximum distance we want to ping for (in centimeters).  Maximum sensor distance is rated at 400 - 500cm
void check();
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void distance();
void blink13();
void blink12();
void blink11();
void blink10();
void blink9();
void blink8();
    boolean led13state = false;
    boolean led12state = false;
    boolean led11state = false;
    boolean led10state = false;
    boolean led9state = false;
    boolean led8state = false;
TimedAction pingAction = TimedAction(10, distance);
TimedAction blink13action = TimedAction(1000, blink13);
TimedAction blink12action = TimedAction(300, blink12);
TimedAction blink11action = TimedAction(500, blink11);
TimedAction blink10action = TimedAction(250, blink10);
TimedAction blink9action = TimedAction(100, blink9);
TimedAction blink8action = TimedAction(750, blink8);
    
void setup () {
	Serial.begin(9600);
	bot.begin();
	pinMode(13, OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
	Serial.println("Hello!");
}

void loop() {
	bot.Speed(leftspeed,rightspeed);
	bot.forward(500);
	
	while (bot.IsRunning()) {
  
		check();	
		bot.update();
			}
	
}

void check() {
  
  pingAction.check();
  blink13action.check();
  blink12action.check();
  blink11action.check();
  blink10action.check();
  blink9action.check();
  blink8action.check();
}

void distance() {

  unsigned int uS = sonar.ping();
  unsigned int sI = (uS / US_ROUNDTRIP_IN);
  
  if (sI >= 30) {
    bot.Speed(leftspeed,rightspeed);
    bot.forward(500);
      }
  
  if (sI > 20 && sI <= 29) {
    bot.Speed(leftspeed - 50, rightspeed - 50);
    bot.forward(500);
      }
  
  if (sI > 5 && sI <= 19) {
    bot.Speed(leftspeed - 75, rightspeed -75);
    bot.forward(500);
      }
  
  if (sI <=5) {
    bot.stop();
    bot.Speed(100,100);
    bot.leftTight(500);
     while (bot.IsRunning()) {
      bot.update();
     }
    bot.stop();
  }
}

void blink13() {
  led13state ? led13state = false : led13state = true;
  digitalWrite(13, led13state);
}

void blink12() {
  led12state ? led12state = false : led12state = true;
  digitalWrite(12, led12state);
}

  void blink11() {
         led11state ? led11state=false : led11state=true;
      digitalWrite(11,led11state);
     }
     
     void blink10() {
        led10state ? led10state=false : led10state=true;
      digitalWrite(10,led10state);
     }
     
     void blink9() {
        led9state ? led9state=false : led9state=true;
      digitalWrite(9,led9state);
     }
     
     void blink8() {
        led8state ? led8state=false : led8state=true;
      digitalWrite(8,led8state);
     }
