// Motor Controls Link to Original Article
// Automation Technology Club
// Motor Controls
// Free to use as you see if - Pin Numbering by Grand Poobah
// Subroutines Aug 18 - LeRoy Miller
// additions will be added for speed correction of wheels
#include "BittyBot.h"

const int PWMLPin = 44; //	Enable PWM Left Motor
const int PWMRPin = 46; //	Enable PWM Right Motor
const int L1Pin = 36; // 	L1 = Left Motor Lead 1
const int L2Pin = 38; // 	L2 = Left Motor Lead 2
const int L3Pin = 40; // 	L3 = Right Motor Lead 1
const int L4Pin = 42; // 	L4 = Right Motor Lead 2
const int LEDPin = 13; // LED
const int MaxSpeed = 255; //not yet used, this will be the max speed your motors can drive at (max PWM) and will be used to help correct for differences in motors
const int CorrectLeft = 0; //to be added later, this will attempt to correct for any motor differances in going forward/backward
const int CorrectRight = 0; //to be added later, this will attempt to correct for any motor differances in going forward/backward
int speed; 

/* FUNCTION CALL USES
lefttight();  //turn in place to the left
righttight(); //turn in place to the right
left();   //turn left going forward
leftb();  //turn left going backward
allstop(); //stop all motors and pwm, small delay for everything to catch up
right(); //turn right going forward
rightb(); //turn right going backward
forward(); //move the robot forward
backward(); // move the robot backward
circleleft(100); //make a left hand circle X number of times
circleright(100); //make a right hand circle  X number of times
*/

BittyBot BittyBot(PWMLPin, PWMRPin, L1Pin, L2Pin, L3Pin, L4Pin);

void setup()
{



}

void loop()
{


//This small section of code shows the relationship of speed vs time 
speed = 65; // speed is set low = slow  
BittyBot.forward(speed); // go forward 
delay(1000); // keep going forward for 1 second
BittyBot.allstop(); // stop all the motors, turn off PWM
delay(2500); // wait..
speed = 100; // set speed to a low meduim speed
BittyBot.backward(speed); // go backward and keep going backward
delay(300); //notice now however time is 300 milli-seconds 
BittyBot.allstop(); //again stop all motors and PWM
delay(2500); //wait


}


