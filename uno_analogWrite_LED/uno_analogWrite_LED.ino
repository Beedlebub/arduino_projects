/*
  Sketch: Brand Inman 2020/08/12
  Change brightness of an LERD with PWM (analogWrite)
*/

// pin connected to LED (with PWM)
int ledPin = 3;

// create a few stored values for brightness levels
int maxBrite = 255;
int medBrite = 100;
int minBrite = 0;

// length of the delay between voltage writes (analogWrite)
int time_delay = 250;

void setup() {
  // put your setup code here, to run once:

  // set our pin's mode to OUTPUT
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  // using a varaible, set the brightness of the LED to max
  analogWrite(ledPin, maxBrite);
  delay(time_delay);
  // using a varaible, set the brightness of the LED somewhere near the middle
  analogWrite(ledPin, medBrite);
  delay(time_delay);
  // using a varaible, set the brightness of the LED to min (off in this case)
  analogWrite(ledPin, minBrite);
  delay(time_delay);
  
}
