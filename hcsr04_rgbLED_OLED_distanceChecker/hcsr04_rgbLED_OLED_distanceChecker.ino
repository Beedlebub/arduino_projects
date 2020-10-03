// Sketch with ping sensor, RGB LED and an OLED screen.
// Ping is just telling us how far it senses something
// LED is just changing colors based on distance...Red, Yellow and Green.
// OLED for basic degugging.

// Include libraries for the OLED
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>

// Set screen size of the OLED
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Spin up SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Pins used for HC-SR04 sensor
const int trigPin = 2;
const int echoPin = 4;
// Setting up float variables for measuring ping signal
float duration, distance_inch, distance_cm;

// Pins used for LED. LED is common-cathode, so we set that setting below.
const int redPin = 11;
const int greenPin = 12;
const int bluePin = 13;
#define COMMON_ANODE ;

void setup() {
  // put your setup code here, to run once:

  // Set up serial output
  Serial.begin(115200);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  // display.display();

  // Invert display color
  // display.invertDisplay(true);

  // Rotate display 180
  display.setRotation(0);

  // Set various bits for how text will render and where
  display.setTextSize(1);              // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);             // Start at top-left corner

  // There is enough space for four lines of text with this screen size. You can
  // specify the stating location of each line, or just print up to four lines
  // after specifting the initial start posistion of 0, 0
  // display.println(F("Line 1"));
  // display.println(F("Line 2"));
  // display.println(F("Line 3"));
  // display.println(F("Line 4"));

  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();

  // Set all LED pins to output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // Set sensor pins to Out for Trig and In for Echo
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Send ping and check for returning signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Uses Pulse
  duration = pulseIn(echoPin, HIGH);
  // Do claculations in centimeters and inches; print
  distance_cm = (duration * .0343) / 2;
  distance_inch = distance_cm * 0.3937;
  // Change color of LED based on proximity
  if (distance_inch <= 6.0) {
    setColor(255, 0, 0); // red
  } else if (distance_inch > 6.0 and distance_inch < 12.0) {
    setColor(255, 255, 0); // yellow
  } else {
    setColor(0, 255, 0); // green
  }
  displayInfo();
  delay(500);
}

void displayInfo() {
  // Debug info in OLED; updates with curruent distance
  display.clearDisplay();
  display.setCursor(0, 0); // Start at top-left corner
  display.println("Inches:");
  display.println(String(distance_inch));
  display.println("Centimeters:");
  display.println(String(distance_cm));
  display.display();
  // Additional serial debug info
  Serial.print("\nDistance in Inches: ");
  Serial.println(distance_inch);
  Serial.print("Distance in Centimeters: ");
  Serial.println(distance_cm);
}

void setColor(int red, int green, int blue) {
  // Special function to help change RGB values to work with common-anode LED
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
