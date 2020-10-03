int ledR = 12; // Arduino Pin 12
int ledG = 11; // Arduino Pin 11
int ledB = 10; // Arduino Pin 10

char val;

void setup() {
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
  Serial1.begin(9600);
  while (!Serial1) {
    ; // wait for serial port to connect. Needed for Leonardo only
  } 
}

// Turn ON Red LED
void go_ledR() {
  digitalWrite(ledR, HIGH);
  digitalWrite(ledG, LOW);
  digitalWrite(ledB, LOW);
}

// TURN ON Green LED
void go_ledG() {
  digitalWrite(ledG, HIGH);
  digitalWrite(ledR, LOW);
  digitalWrite(ledB, LOW);
}

// TURN ON Blue LED
void go_ledB() {
  digitalWrite(ledB, HIGH);
  digitalWrite(ledR, LOW);
  digitalWrite(ledG, LOW);
}

void doThis() {
  if (Serial1.available()) {
    val = Serial1.read();
  }
  if (val == 'r') { // Red LED
    go_ledR();
  } 
  else if (val == 'g') { // Green LED
    go_ledG();
  } 
  else if (val == 'b') { // Bleu LED
    go_ledB();
  }
}

void loop() {
  doThis();
}



