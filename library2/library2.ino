#include "BittyBot2.h"

int _leftEncoderPin = 2;
	int _rightEncoderPin = 3;
	unsigned int _leftrpm;
	unsigned int _rightrpm;
	volatile byte _leftpulses;
	volatile byte _rightpulses;
	unsigned long _encoderTimeOld;
	unsigned int _pulsesperturn = 1;

int leftspeed = 75;
int rightspeed = 75;



BittyBot2 bot(44,46,36,38,40,42); //Left Enable, Right Enable, Pin1 for Left, Pin2 for Left, Pin 1 for Right, Pin 2 for Right

void updaterpm() {
	unsigned long currentMillis = millis();
int tleft = leftspeed;
int tright = rightspeed;
if (currentMillis - _encoderTimeOld >=1000); {
if (_leftpulses > _rightpulses) {tleft = leftspeed - 5;}
if (_leftpulses < _rightpulses) {tleft = leftspeed + 5;}
if (_rightpulses > _leftpulses) {tright = rightspeed - 5;}
if (_rightpulses < _leftpulses) {tright = rightspeed + 5;}

if (tleft >= 255 || tleft <= 0) {tleft = leftspeed;}
if (tright >= 255 || tright <=0) {tright = rightspeed;}
//bot.Speed(0,0);
bot.Speed(tleft, tright);
//analogWrite(44, rightspeed);
//analogWrite(46, leftspeed);

_rightpulses = 0;
_leftpulses = 0;
_encoderTimeOld = currentMillis;
}

	//if (currentMillis - _encoderTimeOld >= 1000) {
//		Serial.print("Pulses = L: ");
//		Serial.print(_leftpulses);
//		Serial.print("  R: ");
//		Serial.println(_rightpulses);
//		_rightrpm = (60 * 1000 / _pulsesperturn)/(currentMillis - _encoderTimeOld) * _rightpulses;
//		_leftrpm = (60 * 1000 / _pulsesperturn)/(currentMillis - _encoderTimeOld) * _leftpulses;
//		_encoderTimeOld=currentMillis;
//		_rightpulses = 0;
//		_leftpulses = 0;
//		Serial.print("RPM = L: ");
//		Serial.print(_leftrpm);
//		Serial.print("  R: ");
//		Serial.println(_rightrpm);
	//}
}

void leftcounter() {
	_leftpulses++;
}

void rightcounter() {
	_rightpulses++;
}

void setup () {
	Serial.begin(9600);
	bot.begin();

	pinMode(_leftEncoderPin, INPUT);
	pinMode(_rightEncoderPin, INPUT);
	attachInterrupt(0, leftcounter, RISING); //left wheel encoder
	attachInterrupt(1, rightcounter, RISING); //right wheel encoder
	
	_leftpulses = 0;
	_rightpulses =0;
	_leftrpm = 0;
	_rightrpm = 0;
	_encoderTimeOld = 0;
	
	//bot.Speed(leftspeed,rightspeed);
	//bot.forward(15000);

	
	Serial.println("Hello!");
}

void loop() {
	bot.Speed(leftspeed,rightspeed);
	bot.forward(15000);
	
	while (bot.IsRunning()) {
		
		Serial.println(bot.IsRunning());
		bot.update();
		updaterpm();
	}
	
	bot.Speed(leftspeed,rightspeed);
	bot.back(15000);
	
	while (bot.IsRunning()) {
		Serial.println("Bot Running");
		bot.update();
		updaterpm();
		}
}
