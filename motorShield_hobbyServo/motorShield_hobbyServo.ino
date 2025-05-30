 /* Sweep
  by BARRAGAN <http://barraganstudio.com>
  This example code is in the public domain.

  modified 8 Nov 2013
  by Scott Fitzgerald
  http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo_1;  // create servo object to control a servo
Servo myservo_2;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo_1.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo_2.attach(10);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo_2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo_2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
