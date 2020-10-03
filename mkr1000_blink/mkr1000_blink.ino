void setup() {
  pinMode(6, OUTPUT);
}
void loop() {
  digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);              // wait for 500ms
  digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);              // wait for 500ms
}
