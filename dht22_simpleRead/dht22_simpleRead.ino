#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// MQTT
const char* mqtt_server = "192.168.0.38";  // IP of the MQTT broker
const char* humidity_topic = "home/livingroom/humidity";
const char* temperature_topic = "home/livingroom/temperature";
const char* clientID = "client_livingroom"; // MQTT client ID

// Initialise the WiFi and MQTT Client objects
WiFiClient wifiClient;
// 1883 is the listener port for the Broker
PubSubClient client(mqtt_server, 1883, wifiClient);


/* How to use the DHT-22 sensor with Arduino uno
   Temperature and humidity sensor
*/
//Constants
#define DHTPIN 14     // what pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); //// Initialize DHT sensor for normal 16mhz Arduino


//Variables
// int chk;
float hum;  // Stores humidity value
float tempC; // Stores Celsius temperature value
float tempF; // Stores Fahrenheit temperature value

// Custom function to connet to the MQTT broker via WiFi
void connect_MQTT() {
  // Wait until the connection has been confirmed before continuing
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Debugging - Output the IP Address of the ESP8266
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Connect to MQTT Broker
  // client.connect returns a boolean value to let us know if the connection was successful.
  // If the connection is failing, make sure you are using the correct MQTT Username and Password (Setup Earlier in the Instructable)
  if (client.connect(clientID)) {
    Serial.println("Connected to MQTT Broker!");
  }
  else {
    Serial.println("Connection to MQTT Broker failed...");
  }
}
void setup()
{
  Serial.begin(115200);
  dht.begin();
}

void loop()
{
  delay(2000);
  //Read data and store it to variables hum and temp
  hum = dht.readHumidity();
  tempC = dht.readTemperature();
  tempF = (tempC * 9 / 5) + 32;

  //Print temp and humidity values to serial monitor
  Serial.println();
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(tempC);
  Serial.print(" Celsius and ");
  Serial.print(tempF);
  Serial.println(" Fahrenheit");
  delay(10000); //Delay 2 sec.
}
