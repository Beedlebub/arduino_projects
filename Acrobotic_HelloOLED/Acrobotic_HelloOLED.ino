/*
  06/01/2016
  Author: Makerbro
  Platforms: ESP8266
  Language: C++
  File: HelloOLED.ino
  ------------------------------------------------------------------------
  Description: 
  Demo for OLED display showcasing writing text to the screen.
  ------------------------------------------------------------------------
  Please consider buying products from ACROBOTIC to help fund future
  Open-Source projects like this! We'll always put our best effort in every
  project, and release all our design files and code for you to use. 
  https://acrobotic.com/
  ------------------------------------------------------------------------
  License:
  Released under the MIT license. Please check LICENSE.txt for more
  information.  All text above must be included in any redistribution. 
*/
#include <Wire.h>
#include <ACROBOTIC_SSD1306.h>

void setup()
{
  Wire.begin();	
  oled.init();                      // Initialze SSD1306 OLED display
  oled.clearDisplay();              // Clear screen
  oled.setTextXY(0,0);              // Set cursor position, start of line 0
  oled.putString("Time, Temp &");
  oled.setTextXY(1,0);              // Set cursor position, start of line 1
  oled.putString("Humidity");
  oled.setTextXY(2,0);              // Set cursor position, start of line 2
  oled.putString("9:30 AM");
  oled.setTextXY(3,0);             // Set cursor position, start of line 3
  oled.putString("64 F");
  oled.setTextXY(4,0);             // Set cursor position, start of line 4
  oled.putString("35 %");
}

void loop()
{
}
