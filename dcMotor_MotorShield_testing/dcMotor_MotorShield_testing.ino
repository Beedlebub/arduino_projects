#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

Adafruit_MotorShield AFMS = Adafruit_MotorShield();

Adafruit_DCMotor *myMotor_3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor_4 = AFMS.getMotor(4);



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello!");
  AFMS.begin();
  
  myMotor_3->setSpeed(150);
  myMotor_4->setSpeed(150);
  
  myMotor_3->run(FORWARD);
  myMotor_4->run(FORWARD);
  
  delay(10000);
  
  myMotor_3->run(RELEASE);
  myMotor_4->run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:

}
