const int buttonA = 5;     // the number of the pushbutton pin
const int buttonB = 11;     // the number of the pushbutton pin

void setup() {
  Serial.begin(115200);

  Serial.println("\nmicro:bit is ready!\n");

  pinMode(buttonA, INPUT);
  pinMode(buttonB, INPUT);
}

void loop() {
  if (! digitalRead(buttonA)) {
    Serial.println("Button A pressed");
    delay(200);
  }
  if (! digitalRead(buttonB)) {
    Serial.println("Button B pressed");
    delay(200);
  }

}
