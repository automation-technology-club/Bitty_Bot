/* BittyBot Drive Library
created by LeRoy Miller, Sept 7 2015
*/

#ifndef BittyBot_h
#define BittyBot_h

#include "Arduino.h"

class BittyBot
{
	public:
	  BittyBot(int PWMLPin, int PWMRPin, int L1Pin, int L2Pin, int L3Pin, int L4Pin);
	  static int _count;
          static int _speed;
          void lefttight(int _speed);
	  void righttight(int _speed);
	  void left(int _speed);
	  void right(int _speed);
	  void leftb(int _speed);
	  void rightb(int _speed);
	  void backward(int _speed);
	  void forward(int _speed);
	  void allstop();
	 //void circleleft(int _count);
	 // void circleright(int _count);
	private:
	  int _PWMLPin;
	  int _PWMRPin;
	  int _L1Pin;
	  int _L2Pin;
	  int _L3Pin;
	  int _L4Pin;
          
};
#endif
