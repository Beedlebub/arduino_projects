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
#include <avr/power.h> // needed to up clock to 16 MHz on 5v Trinket


// Connect via i2c, default address #0 (A0-A2 not jumpered)
TinyLiquidCrystal lcd(0);

int sensorPin = 3;

void setup() {
  // 5V Trinket: run at 16 MHz
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1); 

  // set up the LCD
  lcd.begin(16, 2);            // our display has 16 cols, 2 rows
  lcd.setBacklight(HIGH);      // Turn on the backlight
  //lcd.print("Hello, world!");  // Print a message to the LCD.
}

void loop() {

  //getting the voltage reading from the temperature sensor
  int16_t reading = analogRead(sensorPin);  

  // converting that reading to voltage, for 3.3v arduino use 3.3
  int16_t voltage = reading * 5.0;
  voltage /= 1024.0; 
  lcd.clear();
  lcd.print(voltage); 
  lcd.print(" volts");
  
  delay(1000);

  int16_t temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
  lcd.clear();
  lcd.print(temperatureC); 
  lcd.print(" degrees C");
  
  delay(1000);

  int16_t temperatureF = (temperatureC * 9.0 / 5.0) + 32.0;
  lcd.clear();
  lcd.print(temperatureC); 
  lcd.print(" degrees F");

  delay(1000);
}





