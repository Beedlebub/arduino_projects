#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
char INBYTE;
int  LED = 13; // LED on pin 13

void setup() {
  pinMode(LED, OUTPUT);
  mySerial.begin(9600);
  /*while (!mySerial) {
    // Wait untilSerial is ready - Leonardo
  }
  delay(100); // Test timing for Leonardo; may not do anything
  */
  mySerial.println("Press 1 to turn Arduino pin 13 LED ON or 0 to turn it OFF:");
}

void loop() {
  while (!mySerial.available()); // stay here so long as COM port is empty
  INBYTE = mySerial.read(); // read next available byte
  if (INBYTE == '0')
  {
    digitalWrite(LED, LOW);  // if it's a 0 (zero) tun LED off
    mySerial.println("Pressed 0 and turned LED OFF.");
  }
  else if (INBYTE == '1')
  {
    digitalWrite(LED, HIGH); // if it's a 1 (one) turn LED on
    mySerial.println("Pressed 1 and turned LED ON.");
  }
  else
  {
    mySerial.println("Please only press 0 for OFF or 1 for ON.");
  }
  delay(100); // A little padding so you can't spam buffer
}

