#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Servo.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Set screen size of the OLED
#define SCREEN_WIDTH 128      // OLED display width, in pixels
#define SCREEN_HEIGHT 32      // OLED display height, in pixels
// SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1     // Reset pin # (or -1 if sharing Arduino reset pin)
// Init I2C OLED driver
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Instantiate motor shield as AMFS
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
// Include 2 of 4 motor drivers
Adafruit_DCMotor *myMotor_3 = AFMS.getMotor(3);
Adafruit_DCMotor *myMotor_4 = AFMS.getMotor(4);

// Create 2 servo objects, S1 (Pin 10) and S2 (Pin 9) on board
// Twelve servo objects can be created on most boards
Servo myservo_1;
Servo myservo_2;
// Variable to store a global servo position
int pos = 0;

// Define pins used for each leg of RGB LED
int redPin = 11;
int greenPin = 12;
int bluePin = 13;
// Uncomment this line if using a Common Anode LED
#define COMMON_ANODE


// Variable to debug test 'for' loops in setup
int x = 0;


void setup() {
  // Put your setup code here, to run once:

  // Start serial debug output
  Serial.begin(9600);
  Serial.println("Hello!");

  // Initialize OLED on I2C with several parameters
  oled_init();

  // Set pins used for RGB LED to OUTPUT
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Attaches the servo on pin 9 to the servo object
  myservo_1.attach(10);
  myservo_2.attach(9);

  // Starts the main adafruit motor shield library functionality
  AFMS.begin();

  // Sets motor speed; values from 0 - 255 (max, unless wires are reversed)
  myMotor_3->setSpeed(150);
  myMotor_4->setSpeed(150);

  // Do what happens when we move Forward
  on_forward();

  // Call to sweep the servo left to right
  servo_sweep();


  delay(2000); // NEED TO TEST THIS BEFORE AND AFTER I START SERVO LOOP


  // What happens when we want to Stop
  on_release();

  // Power-down everything when done
  power_down();
}

void loop() {
  // Put your main code here, to run repeatedly:

}

void setColor(int red, int green, int blue) {
// Light up RGB LED with passed in RGB values

// Being honest, I dont know how this works, but you need it when using common anode LEDs
#ifdef COMMON_ANODE
  red = 255 - red;
  green = 255 - green;
  blue = 255 - blue;
#endif
  // Send out voltage value, per RGB LED pin
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}

void power_down() {
  // Call this on any exit to tidy up

  // Turn off LED/OLED to signify powerdown
  delay(2500);
  setColor(0, 0, 0);
  display.clearDisplay();
  display.display();
}

void on_release() {
  // Call this to stop movement

  // Setup OLED
  oled_init();
  // Print direction to OLED
  display.println(F("Released!"));
  display.display();
  // Set RGB LED red as motor moves stops
  setColor(255, 0, 0);
  // Turn off power to motors
  myMotor_3->run(RELEASE);
  myMotor_4->run(RELEASE);
}

void on_forward() {
  // Call this to move motors forward

  // Setup OLED
  oled_init();
  // Print direction to OLED
  display.println(F("Forward!"));
  display.display();
  // Set RGB LED green as motor moves forward
  setColor(0, 255, 0);
  // Tell motors to move FORWARD, REVERSE, or to RELEASE
  myMotor_3->run(FORWARD);
  myMotor_4->run(FORWARD);
}

void servo_sweep() {
  // For now, a simple loop of 5 sweeps total
  for (x = 1; x <= 5; x += 1) {
    // Our sweep goes from 30 degrees to 150 degrees
    // in steps of 1 degree
    for (pos = 30; pos <= 150; pos += 1) {
      // Tell servo to go to position in variable 'pos'
      myservo_1.write(pos);
      myservo_2.write(pos);
      // waits 15ms for the servo to reach the position
      delay(15);                
    }
    // Small pause before sweeping back the other way
    delay(200);
    // Same sweep coming back the other way
    for (pos = 150; pos >= 30; pos -= 1) {
      myservo_1.write(pos);   
      myservo_2.write(pos);
      delay(15);
    }
    delay(200);
  }
}

void oled_init() {
  // Call this during setup() to set up boring bits for using OLED

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {     // Address 0x3C for 128x32
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);     // Don't proceed, loop forever
  }

  // Clear the OLED display buffer
  display.clearDisplay();
  // Show the display buffer on the screen. You MUST call display() after
  // drawing commands to make them visible on screen!
  display.display();
  //// Invert display color
  // display.invertDisplay(true);
  // Rotate display 180
  display.setRotation(0);
  // Set various bits for how text will render and where
  display.setTextSize(2);     // Normal 2:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0);      // Start at top-left corner
}
