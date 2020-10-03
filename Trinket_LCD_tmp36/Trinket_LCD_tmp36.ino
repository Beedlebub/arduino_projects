/*
 Demonstration sketch for Adafruit i2c/SPI LCD backpack
 using MCP23008 I2C expander and the Trinket mini microcontroller
 
 This sketch prints "Hello World!" to the LCD
 and shows a count in seconds.  The circuit:
 
 * 5V to Trinket 5V pin
 * GND to Trinket GND pin
 * CLK to Trinket pin GPIO #2
 * DAT to Trinket pin GPIO #0
 */

// include the library code:
#include <TinyWireM.h>
#include <TinyLiquidCrystal.h>

// Connect via i2c, default address #0 (A0-A2 not jumpered)
TinyLiquidCrystal lcd(0);

int sensorPin = 1;

void setup() {
  // set up the LCD
  lcd.begin(16, 2);            // our display has 16 cols, 2 rows
  lcd.setBacklight(HIGH);      // Turn on the backlight
  //lcd.print("Hello, world!");  // Print a message to the LCD.
}

void loop() {

  //getting the voltage reading from the temperature sensor
  int reading = analogRead(sensorPin);  

  // converting that reading to voltage, for 3.3v arduino use 3.3
  int voltage = reading * 5.0;
  voltage /= 1024.0; 

  // print out the voltage
  lcd.setCursor(0, 0);
  lcd.print(voltage);
  //lcd.setCursor(0, 1);
  lcd.print(" volts");
  
  delay(1000);
}


