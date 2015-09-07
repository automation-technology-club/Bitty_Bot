# Bitty Bot

Testing Library for Bitty Bot Rover.

## Installation

TODO: Describe the installation process

## Usage

include "BittyBot.h"

create a BittyBot object -

BittyBot BittyBot(PWMLPin, PWMRPin, L1Pin, L2Pin, L3Pin, L4Pin);

BittyBot.lefttight(speed);  //turn in place to the left
BittyBot.righttight(speed); //turn in place to the right
BittyBot.left(speed);   //turn left going forward
BittyBot.leftb(speed);  //turn left going backward
BittyBot.allstop(); //stop all motors and pwm, small delay for everything to catch up
BittyBot.right(speed); //turn right going forward
BittyBot.rightb(speed); //turn right going backward
BittyBot.forward(speed); //move the robot forward
BittyBot.backward(speed); // move the robot backward

See Library Sketch for some examples.

## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request

## Credits

LeRoy Miller

This is my very 1st Arduino Library, it wasn't as bad as I thought it would be, but needs some improvements.
Sept 7, 2015

## License

This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses
