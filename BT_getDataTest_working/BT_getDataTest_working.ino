// REMIXED BY: TECHBITAR (HAZIM BITAR)
// LICENSE: PUBLIC DOMAIN
// DATE: MAY 2, 2012
// CONTACT: techbitar at gmail dot com

char INBYTE;
int  LED = 13; // LED on pin 13

void setup() {
  pinMode(LED, OUTPUT);
  Serial1.begin(9600);
  //while(!Serial1); // Wait untilSerial is ready - Leonardo
  //delay(100); // Test timing for Leonardo; may not do anything
  //Serial1.println("Press 1 to turn Arduino pin 13 LED ON or 0 to turn it OFF:");
}

void loop() {
  while(!Serial1.available()); // stay here so long as COM port is empty
  INBYTE = Serial1.read(); // read next available byte
  if(INBYTE == '0') 
  {
    digitalWrite(LED, LOW);  // if it's a 0 (zero) tun LED off
    Serial1.println("Pressed 0 and turned LED OFF.");
  }
  if(INBYTE == '1') 
  {
    digitalWrite(LED, HIGH); // if it's a 1 (one) turn LED on
    Serial1.println("Pressed 1 and turned LED ON.");
  }
  if(INBYTE != '0' || INBYTE != '1')
  {
    Serial1.println("Press 1 to turn LED ON or 0 to turn it off.");
    Serial1.print("You pressed: ");
    Serial1.println(INBYTE);
  }
  delay(100); // A little padding so you can't spam buffer
}











