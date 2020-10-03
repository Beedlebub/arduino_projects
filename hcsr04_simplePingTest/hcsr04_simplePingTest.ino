/*
   HC-SR04 example sketch

   https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380

   by Isaac100
*/

const int trigPin = 2;
const int echoPin = 3;

float duration, distance_inch, distance_cm;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance_cm = (duration * .0343) / 2;
  distance_inch = distance_cm * 0.3937;
  Serial.print("\nDistance in Centimeters: ");
  Serial.println(distance_cm);
  Serial.print("Distance in Inches: ");
  Serial.println(distance_inch);
  delay(1000);
}
