// Constants:
// Analog input pin that the potentiometer is attached to
const int analogInPin = A0;
// Analog output pin that the LED is attached to
const int analogOutPin = 5;

//Variables:
// value read from the pot; set to zero at start
int sensorValue = 0;    
// value output to the PWM (analog out); set to zero at start
int outputValue = 0;
// set a variable to store last loops reading
int last_sensorValue = sensorValue;

void setup() {
  // the setup function runs once when you press reset or power the board

  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Hello!");
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:
  analogWrite(analogOutPin, outputValue);

  // print the results to the Serial Monitor:
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  // wait 2 milliseconds min. before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(20);
  // update the last stored variable                                  
  last_sensorValue = sensorValue;
}
