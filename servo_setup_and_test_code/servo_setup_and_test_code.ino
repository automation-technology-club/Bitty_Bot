int ServoPin = 8;
int CenterServo = 150;
int RightServo = 100;
int LeftServo = 250;

/*This is a Servo Test sketch for use with the BittyBot Rover
and Ultrasonic/with Servo - It took some playing around with
the numbers to finally end up with these. Your Servo will most
likely be different. and it was easier for me to see where the
max was on the left side and work backward. I ended up moving
the servo horn a couple of times, but now it seems fairly
consitant and appears to work.
The way I have the BittyBot code written I'm looking for about
45 degrees from center in both the left and right directions.
*/

void setup() {
  analogWrite(ServoPin, CenterServo);
  delay(1500);
  analogWrite(ServoPin, RightServo);
  delay(1500);
  analogWrite(ServoPin, LeftServo);
  delay(1500);
  analogWrite(ServoPin, CenterServo);
  
}

void loop() {
}
