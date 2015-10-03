/* BittyBot Motor Library version 2
created by LeRoy Miller, Oct 3, 2015
*/

#ifndef BittyBot2_h
#define BittyBot2_h

#include "Arduino.h"

class BittyBot2 {
private:
	int _enableL;
	int _enableR;
	int _Left1; //L1 
	int _Left2; //L2
	int _Right1; //L3
	int _Right2; //L4
	unsigned long _previousMillis;
	long _OnTime;
	int _speedL;
	int _speedR;
    int _isrunning;
    
public: 
BittyBot2(int enableL, int enableR, int Left1, int Left2, int Right1, int Right2) {
	_enableL = enableL;
	_enableR = enableR;
	_Left1 = Left1;
	_Left2 = Left2;
	_Right1 = Right1;
	_Right2 = Right2;
	_previousMillis = 0;
};
#endif
