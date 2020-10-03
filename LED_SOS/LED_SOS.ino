// Project 2 - SOS Morse Code Signaler
// LED connected to digital pin 10
int ledPin = 10;
// run once, when the sketch starts

void setup() {
  // sets the digital pin as output
  pinMode(ledPin, OUTPUT);
}

// run over and over again
void loop() {
  // 3 dits
  for (int x=0; x<3; x++) {
    digitalWrite(ledPin, HIGH);
    delay(150);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  // 100ms delay to cause slight gap between letters
  delay(100);
  // 3 dahs
  for (int x=0; x<3; x++) {
    digitalWrite(ledPin, HIGH);
    delay(400);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  // 100ms delay to cause slight gap between letters
  delay(100);
  // 3 dits again
  for (int x=0; x<3; x++) {
    digitalWrite(ledPin, HIGH);
    delay(150);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  // wait 5 seconds before repeating the SOS signal
  delay(5000);
}

