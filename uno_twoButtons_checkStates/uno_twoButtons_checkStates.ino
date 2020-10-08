// Constants:
// the number of the pushbutton pin
const int BUTTON_1_PIN = 8;
const int BUTTON_2_PIN = 9;

// Variables:
// the previous state from the input pin
int lastState_BUTTON_1 = LOW;
int lastState_BUTTON_2 = LOW;
// the current reading from the input pin
int currentState_BUTTON_1;
int currentState_BUTTON_2;

void setup() {
  // the setup function runs once when you press reset or power the board

  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Hello!");

  // set the two button pins to input, and use a pull-up resistor
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
