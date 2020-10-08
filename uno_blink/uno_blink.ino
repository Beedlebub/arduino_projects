int LED = 6;
int DELAY = 200; //14 I start to see flicker; 12 or less, I don't see flicker

void setup() {
  // the setup function runs once when you press reset or power the board

  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Hello!");

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
  Serial.print("LED is on Pin ");
  Serial.println(LED);
  Serial.print("Blink DELAY is ");
  Serial.println(DELAY);
}

void loop() {
  // the loop function runs over and over again forever

  // turn the LED on (HIGH is the voltage level)
  digitalWrite(LED, HIGH);
  // wait for specified time before doing anything else
  delay(DELAY);
  // turn the LED off by making the voltage LOW
  digitalWrite(LED, LOW);
  // wait again
  delay(DELAY);
}
