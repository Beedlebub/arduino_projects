#include <EduIntro.h>

Button button(D4);
Led led(D5);

void loop()
{
  if (button.readSwitch() == LOW) {
    led.on();
  }
  else {
    led.off();
  }
}
