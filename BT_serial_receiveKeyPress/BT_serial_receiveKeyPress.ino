int incomingByte = 0;   // for incoming serial data

void setup() {
  Serial1.begin(9600);     // opens serial port, sets data rate to 9600 bps
}

void loop() {

  // send data only when you receive data:
  if (Serial1.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial1.read();

    // say what you got:
    Serial1.print("I received: ");
    Serial1.println(incomingByte, DEC);
  }
}


