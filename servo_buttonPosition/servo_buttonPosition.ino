const int BUTTON_A = D5;
const int BUTTON_B = D4;
const int LED = LED_BUILTIN;
int BUTTON_A_state = 0;
int BUTTON_B_state = 0;

void setup()
{
  while (!Serial)
  {
    delay(10);
  }
  Serial.begin(115200);

  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop()
{
  BUTTON_A_state = digitalRead(BUTTON_A);
  if (BUTTON_A_state == HIGH)
  {
    digitalWrite(LED, LOW);
  }

  BUTTON_B_state = digitalRead(BUTTON_B);
  if (BUTTON_B_state == HIGH)
  {
    digitalWrite(LED, HIGH);
  }
  /*
      Further things to add:
      Check if button_a AND button_b are pressed at same time
      Flash the LED 5 times if TRUE
      Add servo
      Move servo to 0 if button_a is pressed
      Move servo to 180 if button_b is pressed
      Move servo tp 90 if a+b are pressed
      Add print stements everywhere
      Add Neopixel and colorize depending on buttons pressed
  */
}
