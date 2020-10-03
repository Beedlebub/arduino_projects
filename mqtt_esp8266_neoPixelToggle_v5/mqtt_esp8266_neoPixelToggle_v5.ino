#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_NeoPixel.h>

// setup for one NeoPixel attached to pin 13
const int PIN = 13;
const int NUMPIXELS = 1;
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// Update these with values suitable for your network.
const char* mqtt_server = "192.168.1.38";

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;
const int MSG_BUFFER_SIZE = (50);
char msg[MSG_BUFFER_SIZE];
int value = 0;

void setup_wifi() {
  delay(10);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
 
  Serial.println();
  /* need to figure out way to get topic data in here.
      can pass in three sepearte topics, or I can find a way
      to parse data in one shot.
  */
  pixels.setPixelColor(0, pixels.Color(64, 64, 64));
  pixels.show();   // Send the updated pixel colors to the hardware.

  // Switch on the LED/Neopixel if an 1 was received as first character
  if ((char)payload[0] == '[') {
    pixels.setPixelColor(0, pixels.Color(255, 255, 255));
    pixels.show();   // Send the updated pixel colors to the hardware.
  }
  else if ((char)payload[0] == ']') {
    pixels.setPixelColor(0, pixels.Color(0, 0, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic", "hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels.clear(); // Set all pixel colors to 'off'
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 2000) {
    lastMsg = now;
    ++value;
    snprintf (msg, MSG_BUFFER_SIZE, "hello world #%ld", value);
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish("outTopic", msg);
  }
}
