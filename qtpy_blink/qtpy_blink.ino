int LED = 3;
int DELAY = 200; //14 I start to see flicker; 12 or less, I don't see flicker

void setup() {
  // the setup function runs once when you press reset or power the board
  
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
}

void loop() {
  // the loop function runs over and over again forever
  
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(DELAY);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(DELAY);                       // wait for a second
}
