#include "Arduino.h"
#include "BittyBot.h"

BittyBot::BittyBot(int PWMLPin, int PWMRPin, int L1Pin, int L2Pin, int L3Pin, int L4Pin)
{
  pinMode (L1Pin, OUTPUT);
pinMode (L2Pin, OUTPUT);
pinMode (L3Pin, OUTPUT);
pinMode (L4Pin, OUTPUT);
pinMode (PWMLPin, OUTPUT);
pinMode (PWMRPin, OUTPUT);

_PWMLPin = PWMLPin;
_PWMRPin = PWMRPin;
_L1Pin = L1Pin;
_L2Pin = L2Pin;
_L3Pin = L3Pin;
_L4Pin = L4Pin;
}

void BittyBot::lefttight(int _speed) {
	digitalWrite (_L1Pin, 1);
	digitalWrite (_L2Pin, 0);
	analogWrite (_PWMLPin, _speed);
	digitalWrite (_L3Pin, 0);
	digitalWrite (_L4Pin, 1);
	analogWrite (_PWMRPin, _speed);
}

void BittyBot::left(int _speed) {
	digitalWrite (_L1Pin, 0);
	digitalWrite (_L2Pin, 0);
	digitalWrite (_L3Pin, 0);
	digitalWrite (_L4Pin, 1);
	analogWrite(_PWMLPin, 0);
	analogWrite(_PWMRPin, _speed);
	
}

void BittyBot::right(int _speed) {
	digitalWrite (_L1Pin, 0);
	digitalWrite (_L2Pin, 1);
	digitalWrite (_L3Pin, 0);
	digitalWrite (_L4Pin, 0);
	analogWrite(_PWMLPin, _speed);
	analogWrite(_PWMRPin, 0);
}

void BittyBot::leftb(int _speed) {
	digitalWrite (_L1Pin, 0);
	digitalWrite (_L2Pin, 0);
	digitalWrite (_L3Pin, 1);
	digitalWrite (_L4Pin, 0);
	analogWrite(_PWMLPin, 0);
	analogWrite(_PWMRPin, _speed);
}

void BittyBot::rightb(int _speed) {
	digitalWrite (_L1Pin, 1);
	digitalWrite (_L2Pin, 0);
	digitalWrite (_L3Pin, 0);
	digitalWrite (_L4Pin, 0);
	analogWrite(_PWMLPin, _speed);
	analogWrite(_PWMRPin, 0);
}
void BittyBot::righttight(int _speed) {
	digitalWrite(_L1Pin, 0);
	digitalWrite(_L2Pin, 1);
	analogWrite (_PWMLPin, _speed);
	digitalWrite(_L3Pin, 1);
	digitalWrite(_L4Pin, 0);
	analogWrite(_PWMRPin, _speed);
}

void BittyBot::backward(int _speed) {
	digitalWrite(_L1Pin, 1);
	digitalWrite(_L2Pin, 0);
	digitalWrite(_L3Pin, 1);
	digitalWrite(_L4Pin, 0);
	analogWrite(_PWMLPin, _speed);
	analogWrite(_PWMRPin, _speed);
}

void BittyBot::forward(int _speed) {
	digitalWrite(_L1Pin, 0);
	digitalWrite(_L2Pin, 1);
	digitalWrite(_L3Pin, 0);
	digitalWrite(_L4Pin, 1);
	analogWrite(_PWMLPin, _speed);
	analogWrite(_PWMRPin, _speed);
	
}

void BittyBot::allstop() {
	digitalWrite(_L1Pin, 0);
	digitalWrite(_L2Pin, 0);
	digitalWrite(_L3Pin, 0);
	digitalWrite(_L4Pin, 0);
	analogWrite(_PWMLPin, 0);
	analogWrite(_PWMRPin, 0);
delay(500);

}

/*
void BittyBot::circleleft(int _count) {
	for (int i=0; i<=_count; i++) {
		BittyBot::left();
	delay(250);	
	}
	BittyBot::allstop();
}

void BittyBot::circleright(int _count) {
	for (int i=0; i<=_count; i++) {
		BittyBot::right();
		delay(250);
	}
	BittyBot::allstop();
}
*/
