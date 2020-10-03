#include <EasyNeoPixels.h>

void setup() {
  // initialize serial:
  Serial.begin(115200);
  delay(2000);
  Serial.println("");
  Serial.println("Ready for input (Enter R,G,B then press Enter Key:");
  // setup for one NeoPixel attached to pin 13
  setupEasyNeoPixels(13, 1);
}

void loop() {
  // if there's any serial available, read it:
  while (Serial.available() > 0) {
    // look for the next valid integer in the incoming serial stream:
    int red = Serial.parseInt();
    // do it again:
    int green = Serial.parseInt();
    // do it again:
    int blue = Serial.parseInt();

    // look for the newline. That's the end of your sentence:
    if (Serial.read() == '\n') {
      // constrain the values to 0 - 255 and invert
      // if you're using a common-cathode LED, just use "constrain(color, 0, 255);"
      red = constrain(red, 0, 255);
      green = constrain(green, 0, 255);
      blue = constrain(blue, 0, 255);

      // turn the NeoPixel ON
      writeEasyNeoPixel(0, red, green, blue);

      // print the three numbers in one string as hexadecimal:
      Serial.print(red, HEX);
      Serial.print(green, HEX);
      Serial.println(blue, HEX);
    }
  }
}
