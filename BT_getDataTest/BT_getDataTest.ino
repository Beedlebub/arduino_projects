// REMIXED BY: TECHBITAR (HAZIM BITAR)
// LICENSE: PUBLIC DOMAIN
// DATE: MAY 2, 2012
// CONTACT: techbitar at gmail dot com

char INBYTE;
int  LED = 13; // LED on pin 13

void setup() {
  Serial1.begin(9600); 
  pinMode(LED, OUTPUT);
}

void loop() {
  Serial1.println("Press 1 to turn Arduino pin 13 LED ON or 0 to turn it OFF:");
  while (!Serial1.available());   // stay here so long as COM port is empty   
  INBYTE = Serial1.read();        // read next available byte
  if( INBYTE == '0' ) digitalWrite(LED, LOW);  // if it's a 0 (zero) tun LED off
  if( INBYTE == '1' ) digitalWrite(LED, HIGH); // if it's a 1 (one) turn LED on
  delay(50);
}
