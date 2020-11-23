#include <PS4Controller.h>
 
void setup()
{
  Serial.begin(115200);
 
  PS4.begin("90:dd:5d:f1:4c:40");
  Serial.println("Initialization ready!");
}
 
void loop()
{
  if(PS4.isConnected()) {
    Serial.println("Controller connected");
  }
 
  delay(1000);
}
