// Include necessary libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// Declarations:

// set screen size of the OLED
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1   // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Set text for various debug output strings
String helloWorld = "Ready!";

void setup() {
  // Code here runs once at startup:

  // Open serial port for debug output and let us know we're ready
  Serial.begin(115200);
  delay(2000);

  Serial.println();
  Serial.println(helloWorld);

  printTextToOLED();
  display.println(helloWorld);
  // Display applicable screen buffer on OLED
  display.display();

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {   // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);   // Don't proceed, loop forever
  }
}

void printTextToOLED() {    // This function allows for printing text to OLED
  // Clear the display buffer
  display.clearDisplay();

  // Show the display buffer on the screen.
  // You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();

  // Invert display color. Commented out (below) for later use.
  // display.invertDisplay(true);

  // Rotate display 180
  display.setRotation(2);

  // Set various bits for how text will render and where
  display.setTextSize(1);   // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);    // Draw white text
  display.setCursor(0, 0);    // Start at top-left corner
}

void loop() {
  // Code here will run repeatedly after setup() is run once:

}
