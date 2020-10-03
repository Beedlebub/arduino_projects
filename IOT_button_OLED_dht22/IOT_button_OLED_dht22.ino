// Include necessary libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// Declarations:
// For the button ...
#define BUTTON_PIN 12   // The number of the pushbutton pin
int lastState = LOW;    // The previous state from the input pin
int currentState;   // The current reading from the input pin

// For the DHT22 and temp values
#define DHTPIN 14   // What pin DHT22 is connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE);   // Initialize DHT sensor
float hum = 0.0;    // Set initial values
float tempC = 0.0;
float tempF = 0.0;
unsigned long previousMillis = 0;   // Will store time last temp was read
const long interval = 2000;   // Interval at which to read sensor

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

  dht.begin();      // start up the DHT sensor
}

void printTextToOLED() {    // This function allows for printing text to OLED
  display.clearDisplay();   // Clear the display buffer

  // Show the display buffer on the screen. 
  // You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();

  // Invert display color. Commented out (below) for later use.
  // display.invertDisplay(true);

  display.setRotation(0);   // Rotate display 180

  // Set various bits for how text will render and where
  display.setTextSize(1);   // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE);    // Draw white text
  display.setCursor(0, 0);    // Start at top-left corner
}

void DHT_readAndStore() {
  // Wait at least 2 seconds seconds between measurements.
  // If the difference between the current time and last time you read
  // the sensor is bigger than the interval you set, read the sensor.
  // Works better than delay for things happening elsewhere also ...
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    // Save the last time you read the sensor
    previousMillis = currentMillis;

    //Read data and store it to variables
    hum = dht.readHumidity();
    tempC = dht.readTemperature();
    tempF = tempC * 9 / 5 + 32;
  }
}

void loop() {
  // Code here will run repeatedly after setup() is run once:

  // Call function to read and store DHT22 data
  // DHT_readAndStore();

  // Read the state of the switch/button:
  currentState = digitalRead(BUTTON_PIN);

  if (lastState == HIGH && currentState == LOW)  {    // Button is pressed
    DHT_readAndStore();   // Call function to read and store DHT22 data
    Serial.println();
    Serial.println(button_pressed);   // Serial output below is for debugging
    Serial.println((String)"Humidity: " + hum);
    Serial.println((String)"Celsius: " + tempC);
    Serial.println((String)"Fahrenheit: " + tempF);

    printTextToOLED();    // Calls function to set up OLED for updated info
    display.println((String) "Humidity: " + int(round(hum)) + "%");
    display.println((String) int(round(tempC)) + char(9) + " C");
    display.println((String) int(round(tempF)) + char(9) + " F");
  }

  else if (lastState == LOW && currentState == HIGH) {    // Button is released
    Serial.println(button_released);
    display.clearDisplay();
  }

  // Display applicable screen buffer on OLED
  display.display();

  // Save the the last state of button
  lastState = currentState;
  delay(20);    // debounce timer
}
