#include "Arduino.h"
#include "BittyBot2.h"

BittyBot2::BittyBot2(int enableL, int enableR, int Left1, int Left2, int Right1, int Right2); 

void begin() {
	pinMode(_enableL, OUTPUT);
	pinMode(_enableR, OUTPUT);
	pinMode(_Left1, OUTPUT);
	pinMode(_Left2, OUTPUT);
	pinMode(_Right1, OUTPUT);
	pinMode(_Right2, OUTPUT);
	calibrate();
	digitalWrite(_Left1, LOW);
	digitalWrite(_Left2, LOW);
	digitalWrite(_Right1, LOW);
	digitalWrite(_Right2, LOW);
	Speed(0,0);

}
 
void Speed(int speedL, int speedR) {
	_speedL = speedL;
	_speedR = speedR;
	//digitalWrite(_Left1, LOW);
	//digitalWrite(_Left2, LOW);
	//digitalWrite(_Right1, LOW);
	//digitalWrite(_Right2, LOW);
	analogWrite(_enableL, _speedL);
	analogWrite(_enableR, _speedR);

}

void stop() {

	digitalWrite(_Left1, LOW);
	digitalWrite(_Left2, LOW);
	digitalWrite(_Right1, LOW);
	digitalWrite(_Right2, LOW);
	Speed(0,0);
	_isrunning = 0;
}

void forward(int OnTime) {
	digitalWrite(_Left1, LOW);
	digitalWrite(_Left2, HIGH);
	digitalWrite(_Right1, LOW);
	digitalWrite(_Right2, HIGH);
	_OnTime = OnTime;
	_isrunning = 1;
}

void back(int OnTime) {
	digitalWrite(_Left1, HIGH);
	digitalWrite(_Left2, LOW);
	digitalWrite(_Right1, HIGH);
	digitalWrite(_Right2, LOW);
	_OnTime = OnTime;
	_isrunning = 1;

}

void rightTight(int OnTime) {
	digitalWrite(_Left1, LOW);
	digitalWrite(_Left2, HIGH);
	digitalWrite(_Right1, HIGH);
	digitalWrite(_Right2, LOW);
	_OnTime = OnTime;
	_isrunning = 1;
}

void leftTight(int OnTime) {
	digitalWrite(_Left1, HIGH);
	digitalWrite(_Left2, LOW);
	digitalWrite(_Right1, LOW);
	digitalWrite(_Right2, HIGH);
	_OnTime = OnTime;
	_isrunning = 1;
}

void right(int OnTime) {
	digitalWrite(_Left1, LOW);
	digitalWrite(_Left2, HIGH);
	digitalWrite(_Right1, LOW);
	digitalWrite(_Right2, LOW);
	analogWrite(_enableR, 0);
	_OnTime = OnTime;
	_isrunning = 1;
}

void left(int OnTime) {
	digitalWrite(_Left1, LOW);
	digitalWrite(_Left2, LOW);
	digitalWrite(_Right1, LOW);
	digitalWrite(_Right2, HIGH);
	analogWrite(_enableL, 0);
	_OnTime = OnTime;
	_isrunning = 1;
}

void update() {
	unsigned long currentMillis = millis();
	if (currentMillis - _previousMillis >= _OnTime) {
		_previousMillis = currentMillis;
		stop();
		Speed(_speedL, _speedR);
	}
}

void calibrate() {
//We need to know where the magnets are at the start, that is what this is suppose to do, give a common starting point.
	Speed(50,50);
		while (digitalRead(3) != HIGH) {
		
		right(1000);
			}
			stop();
			Speed(50,50);
		while (digitalRead(2) != HIGH) {
		
		left(1000);
	}
	stop();
	Speed(0,0);
}

int IsRunning() {
	return (_isrunning);
}
};
