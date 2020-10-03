// REMIXED BY: TECHBITAR (HAZIM BITAR)
// LICENSE: PUBLIC DOMAIN
// DATE: MAY 2, 2012
// CONTACT: techbitar at gmail dot com

int counter = 0;

void setup() {
  Serial1.begin(9600); 
  delay(50);
}

void loop() {
  counter++;
  Serial1.print("Arduino counter: ");
  Serial1.println(counter);
  delay(1000); // wait half a sec
}
