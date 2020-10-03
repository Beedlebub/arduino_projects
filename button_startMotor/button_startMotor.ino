/*
  This is a test sketch for the Adafruit assembled Motor Shield for Arduino v2
  It won't work with v1.x motor shields! Only for the v2's with built in PWM
  control

  For use with the Adafruit Motor Shield v2
  ---->	http://www.adafruit.com/products/1438
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Setup the button
// Constants:
const int BUTTON_PIN = 12; // the number of the pushbutton pin
// Variables:
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Or, create it with a different I2C address (say for stacking)
// Adafruit_MotorShield AFMS = Adafruit_MotorShield(0x61);

// Select which 'port' M1, M2, M3 or M4. In this case, M1
Adafruit_DCMotor *myMotor = AFMS.getMotor(3);
// You can also make another motor on port M2
//Adafruit_DCMotor *myOtherMotor = AFMS.getMotor(2);

void setup() {
  Serial.begin(115200);           // set up Serial library at 9600 bps

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  Serial.println("Adafruit Motorshield v2 - DC Motor test!");
  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz

  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotor->setSpeed(100);
  myMotor->run(FORWARD);
  // turn on motor
  myMotor->run(RELEASE);
}

void loop() {
  uint8_t i;

  currentState = digitalRead(BUTTON_PIN);

  if (lastState == HIGH && currentState == LOW)      { // button is pressed
    Serial.println("Button pressed!");
  }
  else if (lastState == LOW && currentState == HIGH) { // button is released
    Serial.println("Button released!");
  }
  // save the the last state
  lastState = currentState;

  Serial.print("\ntick");
  myMotor->run(FORWARD);
  for (i = 0; i < 255; i++) {
    myMotor->setSpeed(i);
    delay(10);
  }
  for (i = 255; i != 0; i--) {
    myMotor->setSpeed(i);
    delay(10);
  }

  Serial.print("\ntock");
  myMotor->run(BACKWARD);
  for (i = 0; i < 255; i++) {
    myMotor->setSpeed(i);
    delay(10);
  }
  for (i = 255; i != 0; i--) {
    myMotor->setSpeed(i);
    delay(10);
  }

  Serial.print("\ntech");
  myMotor->run(RELEASE);
  delay(1000);
}
