/* 
    Make sure your choose correct board (e.g. Arduino Uno) and the Serial Port
    Test (3) LEDs by uploading the code below
*/

int led1 = 12;  // Arduino Pin 12
int led2 = 11; // Arduino Pin 11
int led3 = 10;  // Arduino Pin 10

void setup() {

  // initialize the digital pins as output
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);

}

void loop() {
  digitalWrite(led1, HIGH);   // turn the LED ON
  delay(1000);                        // wait for a second
  digitalWrite(led1, LOW);    // turn the LED OFF
  delay(1000);                        // wait for a second

  digitalWrite(led2, HIGH);   // turn the LED ON
  delay(1000);                        // wait for a second
  digitalWrite(led2, LOW);    // turn the LED OFF
  delay(1000);                        // wait for a second

  digitalWrite(led3, HIGH);   // turn the LED ON
  delay(1000);                        // wait for a second
  digitalWrite(led3, LOW);    // turn the LED OFF
  delay(1000);                         // wait for a second

}

// code ends here

