/* Hey guys!
   This code is designed to take in data from a standard
   PS4 controller, and use that data to control the ESP32
   Voyager, and Explorer Robot.  Feel free to alter, or
   customize this code as you'd like.  Have fun!

   - Matt ACBR 2020
*/
#include <PS4Controller.h>
#include <Arduino.h>
#include <analogWrite.h>
#include <esp32-hal-ledc.h>

#define COUNT_LOW 1638
#define COUNT_HIGH 7864
#define TIMER_WIDTH 16

int posOne = 5000;
int posTwo = 6000;
int posThree = 5000;
int inOne = 12;
int inTwo = 13;
int inThree = 16;
int inFour = 17;
int inFive = 23;
int inSix = 22;
int inSeven = 19;
int inEight = 18;
int rX;
int rY;
int lX;
int lY;

void setup()
{
  Serial.begin(115200);
  PS4.begin("90:dd:5d:f1:4c:40");
  Serial.println("Ready.");
  pinMode(inOne, OUTPUT);
  pinMode(inTwo, OUTPUT);
  pinMode(inThree, OUTPUT);
  pinMode(inFour, OUTPUT);
  pinMode(inFive, OUTPUT);
  pinMode(inSix, OUTPUT);
  pinMode(inSeven, OUTPUT);
  pinMode(inEight, OUTPUT);
  ledcSetup(15, 50, TIMER_WIDTH); // channel 15, 50 Hz, 16-bit width
  ledcAttachPin(25, 15);   // GPIO 25 assigned to channel 15
  ledcSetup(14, 50, TIMER_WIDTH); // channel 14, 50 Hz, 16-bit width
  ledcAttachPin(27, 14);   // GPIO 27 assigned to channel 14
  ledcAttachPin(26, 14);   // GPIO 26 assigned to channel 14
  ledcSetup(13, 50, TIMER_WIDTH); // channel 15, 50 Hz, 16-bit width
  ledcAttachPin(14, 13);   // GPIO 14 assigned to channel 13
  ledcWrite(15, posOne);
  ledcWrite(14, posTwo);
  ledcWrite(13, posThree);
}

void loop()
{
  if (PS4.isConnected()) {
    lX = (PS4.data.analog.stick.lx);
    lY = (PS4.data.analog.stick.ly);
    rX = (PS4.data.analog.stick.rx);
    rY = (PS4.data.analog.stick.ry);

    Serial.print(lX);
    Serial.print(" ");
    Serial.print(lY);
    Serial.print(" ");
    Serial.print(rX);
    Serial.print(" ");
    Serial.println(rY);

    if (lY < -5) {
      analogWrite(inOne, 0);
      analogWrite(inTwo, 200);
      analogWrite(inThree, 0);
      analogWrite(inFour, 200);
      analogWrite(inFive, 0);
      analogWrite(inSix, 200);
      analogWrite(inSeven, 0);
      analogWrite(inEight, 200);
      Serial.println("Forward!");
    }
    else if (lY > 5) {
      analogWrite(inOne, 200);
      analogWrite(inTwo, 0);
      analogWrite(inThree, 200);
      analogWrite(inFour, 0);
      analogWrite(inFive, 200);
      analogWrite(inSix, 0);
      analogWrite(inSeven, 200);
      analogWrite(inEight, 0);
      Serial.println("Backward!");
    }
    else if (lX < -5) {
      analogWrite(inOne, 255);
      analogWrite(inTwo, 0);
      analogWrite(inThree, 255);
      analogWrite(inFour, 0);
      analogWrite(inFive, 0);
      analogWrite(inSix, 255);
      analogWrite(inSeven, 0);
      analogWrite(inEight, 255);
      Serial.println("Left!");
    }
    else if (lX > 5) {
      analogWrite(inOne, 0);
      analogWrite(inTwo, 255);
      analogWrite(inThree, 0);
      analogWrite(inFour, 255);
      analogWrite(inFive, 255);
      analogWrite(inSix, 0);
      analogWrite(inSeven, 255);
      analogWrite(inEight, 0);
      Serial.println("Right!");
    }
    else if (rX < -5 && posOne < 8000) {
      ledcWrite(15, posOne);
      posOne += 25;
    }
    else if (rX > 5 && posOne > 1500) {
      ledcWrite(15, posOne);
      posOne -= 25;
    }
    else if (rY < -5 && posTwo < 8000) {
      ledcWrite(14, posTwo);
      posTwo += 25;
    }
    else if (rY > 5 && posTwo > 150) {
      ledcWrite(14, posTwo);
      posTwo -= 25;
    }
    else if ( abs(PS4.data.button.l2) ) {
      ledcWrite(13, posThree);
      posThree += 25;
    }
    else if ( abs(PS4.data.button.r2) ) {
      ledcWrite(13, posThree);
      posThree -= 25;
    }
    else {
      analogWrite(inOne, 255);
      analogWrite(inTwo, 255);
      analogWrite(inThree, 255);
      analogWrite(inFour, 255);
      analogWrite(inFive, 255);
      analogWrite(inSix, 255);
      analogWrite(inSeven, 255);
      analogWrite(inEight, 255);
    }
  }
}
