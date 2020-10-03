const int BUTTON_A = 2;
const int BUTTON_B = 4;
const int LED1 = LED_BUILTIN;
const int LED2 = 12;
int BUTTON_A_state = 0;
int BUTTON_B_state = 0;

void setup()
{
  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW);
}

void loop()
{
  BUTTON_A_state = digitalRead(BUTTON_A);
  if (BUTTON_A_state == LOW)
  {
    digitalWrite(LED1, HIGH);
  }
  /*
  else {
    digitalWrite(LED1, LOW);
  }
  */

  BUTTON_B_state = digitalRead(BUTTON_B);
  if (BUTTON_B_state == LOW)
  {
    digitalWrite(LED1, LOW);
  }
  /*
  else {
    digitalWrite(LED1, HIGH);
  }
  */
}
