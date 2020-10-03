// Sketch with ping sensor, RGB LED and an OLED screen.
// Ping is just telling us how far it senses something
// LED is just changing colors based on distance...Red, Yellow and Green.
// I plan to add OLED for basic deguggin on all projects.


// Pins used for HC-SR04 sensor
const int trigPin = 2;
const int echoPin = 3;
// Setting up float variables for measuring ping signal
float duration, distance_inch, distance_cm;

// Pins used for LED. LED is common-cathode, so we set that setting below.
const int redPin = 11;
const int greenPin = 12;
const int bluePin = 13;
#define COMMON_ANODE;

void setup() {
  // put your setup code here, to run once:


  // Set all LED pins to output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  // Set sensor pins to Out for Trig and In for Echo
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //Set up serial output
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  // Integrate this into the distance calculation
  setColor(255, 0, 0);  // red
  delay(1000);
  setColor(0, 255, 0);  // green
  delay(1000);
  setColor(0, 0, 255);  // blue
  delay(1000);

  // Send and check for returning signal
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  //Uses Pulse
  duration = pulseIn(echoPin, HIGH);
  // Do claculations in centimeters and inches; print
  distance_cm = (duration * .0343) / 2;
  distance_inch = distance_cm * 0.3937;
  Serial.print("\nDistance in Centimeters: ");
  Serial.println(distance_cm);
  Serial.print("Distance in Inches: ");
  Serial.println(distance_inch);
  delay(1000);
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
