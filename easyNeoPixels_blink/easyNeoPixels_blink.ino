#include <EasyNeoPixels.h>

void setup() {
    // setup for one NeoPixel attached to pin 11
    setupEasyNeoPixels(11, 1);
}

void loop() {
    // turn the NeoPixel ON
    writeEasyNeoPixel(0, 255, 255, 255);
    delay(500);
    // turn the NeoPixel OFF
    writeEasyNeoPixel(0, 0, 0, 0);
    delay(500);
}
