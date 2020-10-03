#include <Servo.h>

Servo myservo_1;  // create servo object to control a servo
Servo myservo_2;
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservo_1.attach(10);  // attaches the servo on pin 9 to the servo object
  myservo_2.attach(9);
}

void loop() {
  for (pos = 30; pos <= 150; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo_2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(200);
  for (pos = 150; pos >= 30; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo_1.write(pos);              // tell servo to go to position in variable 'pos'
    myservo_2.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(200);
}
