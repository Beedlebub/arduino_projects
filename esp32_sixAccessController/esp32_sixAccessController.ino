#include <PS4Controller.h>

void setup()
{
    Serial.begin(115200);
    PS4.begin("90:dd:5d:f1:4c:40");
    Serial.println("Ready.");
}

void loop()
{
		// Below has all accessible outputs from the controller
    if(PS4.isConnected()) {
			if ( PS4.data.button.up )
					Serial.println("Up Button");
			if ( PS4.data.button.down )
					Serial.println("Down Button");
			if ( PS4.data.button.left )
					Serial.println("Left Button");
			if ( PS4.data.button.right )
					Serial.println("Right Button");
				
			if ( PS4.data.button.upright )
					Serial.println("Up Right");
			if ( PS4.data.button.upleft )
					Serial.println("Up Left");
			if ( PS4.data.button.downleft )
					Serial.println("Down Left");
			if ( PS4.data.button.downright )
					Serial.println("Down Right");
				
			if ( PS4.data.button.triangle )
					Serial.println("Triangle Button");
			if ( PS4.data.button.circle )
					Serial.println("Circle Button");
			if ( PS4.data.button.cross )
					Serial.println("Cross Button");
			if ( PS4.data.button.square )
					Serial.println("Square Button");

		 // This delay is to make the Serial Print more human readable
		 // Remove it when you're not trying to see the output
     delay(150);
    }
}
