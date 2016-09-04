#include "BittyBot2.h"

int leftspeed = 175;
int rightspeed = 175;

BittyBot bot(44,46,36,38,40,42); //Left Enable, Right Enable, Pin1 for Left, Pin2 for Left, Pin 1 for Right, Pin 2 for Right

void setup () {
	Serial.begin(9600);
	bot.begin();
	
	Serial.println("Hello!");
}

void loop() {
	bot.Speed(leftspeed,rightspeed);
	bot.forward(1500);
	
	while (bot.IsRunning()) {
		
		Serial.println(bot.IsRunning());
		bot.update();
			}
	
	bot.Speed(leftspeed,rightspeed);
	bot.back(1500);
	
	while (bot.IsRunning()) {
		Serial.println("Bot Running");
		bot.update();
				}
}
