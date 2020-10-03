// Constants:
const int BUTTON_PIN = 12; // the number of the pushbutton pin

// Variables:
int lastState = LOW;  // the previous state from the input pin
int currentState;     // the current reading from the input pin


void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop() {
  // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  if (lastState == HIGH && currentState == LOW)      { // button is pressed
    Serial.println("Button pressed!");
  }
  else if (lastState == LOW && currentState == HIGH) { // button is released
    Serial.println("Button released!");
  }

  // save the the last state
  lastState = currentState;
  delay(20);
}
