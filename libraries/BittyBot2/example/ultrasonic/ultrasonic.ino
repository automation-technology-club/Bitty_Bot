#include "BittyBot2.h"
#include <NewPing.h>
#include <TimedAction.h>

int leftspeed = 175;
int rightspeed = 175;

BittyBot bot(44,46,36,38,40,42); //Left Enable, Right Enable, Pin1 for Left, Pin2 for Left, Pin 1 for Right, Pin 2 for Right

#define TRIGGER_PIN 5 //Arduino Pin Tied to Trigger Pin on the ultrasonic sensor
#define ECHO_PIN 6 //Arduino Pin Tied to echo pin on the ultrasonic sensor
#define MAX_DISTANCE 500 //Maximum distance we want to ping for (in centimeters).  Maximum sensor distance is rated at 400 - 500cm

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
void distance();
TimedAction pingAction = TimedAction(10, distance);

void setup () {
	Serial.begin(9600);
	bot.begin();
	
	Serial.println("Hello!");
}

void loop() {
	bot.Speed(leftspeed,rightspeed);
	bot.forward(500);
	
	while (bot.IsRunning()) {
  
		pingAction.check();	
		bot.update();
			}
	
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
