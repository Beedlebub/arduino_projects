#include <Streaming.h>  // Imparts no overhead in code size
#include <SoftwareSerial.h>  // Software serial library (standard in Arduino 1.x +)

const byte txPin = 0;
const byte rxPin = 2;

SoftwareSerial Serial(rxPin, txPin);

void setup() {
  //Serial << "\r" ;
  //Serial.begin(9600);
  //Serial.println("Bluetooth Ready.");
  //delay(1000);
  //Serial << ("Waiting...");
  //delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello, world");
  delay(1000);
}

