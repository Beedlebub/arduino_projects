/* SerialTemp example

  Copyright 2017 Isaac100

  This exmaple writes the current temperarure in celsius
  and fahrenheit to the serial monitor.

*/

#include <TMP36.h>

//Create an instance of the TMP36 class and
//define the pin the sensor is connected to
//If using 3.3v Arduino, change 5 to 3.3
TMP36 myTMP36(A0, 3.3);

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
  //create a variable and store the current temperature in
  //celius in it using the getTempC function
  float celsius = myTMP36.getTempC();

  //create a variable and store the current temperature in
  //fahrenheit in it using the getTempF function
  float fahrenheit = myTMP36.getTempF();

  //Print the data to the Serial monitor
  Serial.print("Celsius: ");
  Serial.print(celsius);
  Serial.print(" Fahrenheit: ");
  Serial.println(fahrenheit);
  delay(5000);
}
