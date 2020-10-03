// Library to set Trinket to 16MHz
#include <avr/power.h>

const byte GREEN = 0;
const byte BLUE = 1;
const byte RED = 4;
const int delayTime = 30; // increase this value to increase the fading time between colors

void setup() 
{
  // sets Trinket to 16MHz
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);

  PWM4_init();

  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(RED, OUTPUT);

  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, HIGH);
  digitalWrite(RED, HIGH);
}

int redVal;
int blueVal;
int greenVal;

void loop() 
{
  redVal = 255; // choose a value between 1 and 255 to change the color. 
  blueVal = 0;
  greenVal = 0;
  for(int i = 0; i < 255; i += 1) // fades out of red and into full (i = 255) green
  {
    greenVal += 1;
    redVal -= 1;
    analogWr(GREEN, 255 - greenVal);
    analogWr(RED, 255 - redVal);
    delay(delayTime);
  }

  redVal = 0;
  blueVal = 0;
  greenVal = 255;
  for(int i = 0; i < 255; i += 1)
  {
    blueVal += 1;
    greenVal -= 1;
    analogWr(BLUE, 255 - blueVal);
    analogWr(GREEN, 255 - greenVal);
    delay(delayTime);
  }

  redVal = 0;
  blueVal = 255;
  greenVal = 0;
  for(int i = 0; i < 255; i += 1)
  {
    redVal += 1;
    blueVal -= 1;
    analogWr(RED, 255 - redVal);
    analogWr(BLUE, 255 - blueVal);
    delay(delayTime);
  }
}

// Set up PWM on Trinket GPIO #4 (PB4, pin 3) using Timer 1
void PWM4_init() {
  TCCR1 = _BV (CS10); // no prescaler
  GTCCR = _BV (COM1B1) | _BV (PWM1B); // clear OC1B on compare
  OCR1B = 127; // duty cycle initialize to 50%
  OCR1C = 255; // frequency
}

// A single function to handle PWM any pin
void analogWr(int pin, uint8_t value) {
  if (pin == 4) {
    OCR1B = value; // The PWM duty value between 0 and 255 (0 to 100%)
  } 
  else {
    analogWrite(pin, value);
  }
}




