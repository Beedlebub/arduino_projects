// Include necessary libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
// #include <DHT.h>

// Declarations:
// for the button ...
#define BUTTON_PIN 12      // the number of the pushbutton pin
int lastState = LOW;      // the previous state from the input pin
int currentState;     // the current reading from the input pin

// for the DHT22 and temp values
// #define DHTPIN 14     // what pin we're connected to
// #define DHTTYPE DHT22   // DHT 22  (AM2302)
// DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino
// float humidity = 0.0;
// float tempC = 0.0;
// float tempF = 0.0;

// set screen size of the OLED
#define SCREEN_WIDTH 128      // OLED display width, in pixels
#define SCREEN_HEIGHT 32      // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1     // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Set text for various output strings
String hello = "Ready!";
String button_pressed = "Button pressed!";
String button_released = "Button released";

void setup() {
  // put your setup code here, to run once:

  // Open serial port for debug output and let us know we're ready
  Serial.begin(115200);
  delay(1000);
  
  Serial.println(hello);

  printTextToOLED();
  display.println(hello);
  display.display();

  // Establish parameters for pin used with pushbutton
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {     // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);     // Don't proceed, loop forever
  }
}

void printTextToOLED() {
  display.clearDisplay();     // Clear the display buffer

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();

  display.invertDisplay(true);     // Invert display color

  display.setRotation(2);     // Rotate display 180

  // Set various bits for how text will render and where
  display.setTextSize(1);     // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);      // Start at top-left corner
}

void loop() {
  // put your main code here, to run repeatedly:

  // read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  if (lastState == HIGH && currentState == LOW)  {   // button is pressed
    Serial.println(button_pressed);
    printTextToOLED();
    display.println(button_pressed);
  }
  else if (lastState == LOW && currentState == HIGH) {      // button is released
    Serial.println(button_released);
    printTextToOLED();
    display.println(button_released);
  }

  display.display();
  // save the the last state
  lastState = currentState;
  delay(20);
}
