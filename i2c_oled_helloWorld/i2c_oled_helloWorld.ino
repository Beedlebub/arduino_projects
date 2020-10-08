
// Include necessary libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// set screen size of the OLED
#define SCREEN_WIDTH 128      // OLED display width, in pixels
#define SCREEN_HEIGHT 64      // OLED display height, in pixels

// SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1     // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Open serial port for debug output
  Serial.begin(115200);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {     // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);     // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();

  // Invert display color
  // display.invertDisplay(true);

  // Rotate display 180
  display.setRotation(0);

  // Set various bits for how text will render and where
  display.setTextSize(1);     // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);      // Start at top-left corner

  // There is enough space for four lines of text with this screen size. You can specify the stating location of each line, or just print up to four lines after specifting the initial start posistion of 0, 0
  display.println(F("Line 1"));
  display.println(F("Line 2"));
  display.println(F("Line 3"));
  display.println(F("Line 4"));

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}
