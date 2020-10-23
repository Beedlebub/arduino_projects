// Constants:
const int BUTTON_1_PIN = 1; // the number of the pushbutton pin
const int BUTTON_2_PIN = 2;

// Variables:
int lastState_BUTTON_1 = LOW;  // the previous state from the input pin
int currentState_BUTTON_1;     // the current reading from the input pin
int lastState_BUTTON_2 = LOW;
int currentState_BUTTON_2;

void setup() {
  // code here runs once at boot
  Serial.begin(115200);
  Serial.println("Hello!");
  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
}

void loop() {
  // code below runs as a loop until loop is broken

  button_1_checks();
  button_2_checks();
}

void button_1_checks() {  
  // read votage state of button pin
  currentState_BUTTON_1 = digitalRead(BUTTON_1_PIN);
  // compare last and current states
  if (lastState_BUTTON_1 == HIGH && currentState_BUTTON_1 == LOW)      { // button is pressed
    Serial.println("Button 1 pressed!");
  }
  else if (lastState_BUTTON_1 == LOW && currentState_BUTTON_1 == HIGH) { // button is released
    Serial.println("Button 1 released!");
  }
  // save the the last state as the current state
  lastState_BUTTON_1 = currentState_BUTTON_1;
  // delay to help with debouncing button
  delay(20);
}

void button_2_checks() {
  // read votage state of button pin
  currentState_BUTTON_2 = digitalRead(BUTTON_2_PIN);
  // compare last and current states
  if (lastState_BUTTON_2 == HIGH && currentState_BUTTON_2 == LOW)      { // button is pressed
    Serial.println("Button 2 pressed!");
  }
  else if (lastState_BUTTON_2 == LOW && currentState_BUTTON_2 == HIGH) { // button is released
    Serial.println("Button 2 released!");
  }
  // save the the last state as the current state
  lastState_BUTTON_2 = currentState_BUTTON_2;
  // delay to help with debouncing button
  delay(20);
}
