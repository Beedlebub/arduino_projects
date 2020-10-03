// Include necessary libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


// Declarations:
// For the button ...
#define BUTTON_PIN 12   // The number of the pushbutton pin
int lastState = LOW;    // The previous state from the input pin; off
int currentState;   // The current reading from the input pin

// set screen size of the OLED
#define SCREEN_WIDTH 128    // OLED display width, in pixels
#define SCREEN_HEIGHT 64    // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1   // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Set text for various debug output strings
String helloWorld = "Ready!";
String button_pressed = "Button pressed!";
String button_released = "Button released...";

void setup() {
  // Code here runs once at startup:

  // Open serial port for debug output and let us know we're ready
  Serial.begin(115200);
  delay(2000);
  Serial.println();
  Serial.println(helloWorld);

  // Set parameters for pin used with pushbutton
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {   // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);   // Don't proceed, loop forever
  }
}

void printTextToOLED() {    // This function allows for printing text to OLED
  display.clearDisplay();   // Clear the display buffer

  // Show the display buffer on the screen.
  // You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();

  // Invert display color. Commented out (below) for later use.
  // display.invertDisplay(true);

  display.setRotation(2);   // Rotate display 180

  // Set various bits for how text will render and where
  display.setTextSize(1);   // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);    // Draw white text
  display.setCursor(0, 0);    // Start at top-left corner
}

void loop() {
  // Code here will run repeatedly after setup() is run once:

  // Read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  if (lastState == HIGH && currentState == LOW)  {    // Button is pressed
    Serial.println();
    Serial.println(button_pressed);   // Serial output below is for debugging
    printTextToOLED();    // Calls function to set up OLED for updated info
    display.println(button_pressed);
  }

  else if (lastState == LOW && currentState == HIGH) {    // Button is released
    Serial.println(button_released);
    printTextToOLED();
    display.println(button_released);
    // display.clearDisplay();
  }

  // Display applicable screen buffer on OLED
  display.display();

  // Save the the last state of button
  lastState = currentState;
  delay(20);    // debounce timer
}
