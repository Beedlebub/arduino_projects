/*
  Sketch: Brand Inman 2020/08/12
  Uses LEDs to count through 0-15 in Binary (4-bits)
*/

// delay between numbers
int time_delay = 750;

// array to make setup of multiple LED pins easier
int ledPins[] = {
  2, 3, 4, 5
};

// the array elements are numbered from 0 to (pinCount - 1)
int pinCount = 4;

void setup() {
  // put your setup code here, to run once:

  // open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    // wait for serial port to connect (Needed for native USB port only)
    ;
  }
  // print something to confirm Serial is working:
  Serial.println("Hello! Serial comms started...\n");

  // use a 'for' loop to initialize each pin in array as an output:
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }
}


void loop() {
  // put your main code here, to run repeatedly:

  /*
    each function call below runs the respective
    code to turn the correct LEDs on and off per
    number currently being counted
  */
  count_00();
  count_01();
  count_02();
  count_03();
  count_04();
  count_05();
  count_06();
  count_07();
  count_08();
  count_09();
  count_10();
  count_11();
  count_12();
  count_13();
  count_14();
  count_15();
  // restart the loop ...
}

void count_00() {
  // function to turn on/off LEDs for respective number

  // print the number being counted's info in Serial Monitor
  Serial.println("Decimal: 00\t Binary: 0000");

  // set the pins HIGH or LOW for the binary number
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);

  // set a timer for how long this number should remain active and visible
  delay(time_delay);

  // quick way to 'clear' all the pins before going to next one (helps reduce visible lag)
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_01() {
  Serial.println("Decimal: 01\t Binary: 0001");
  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_02() {
  Serial.println("Decimal: 02\t Binary: 0010");
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_03() {
  Serial.println("Decimal: 03\t Binary: 0011");
  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], LOW);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_04() {
  Serial.println("Decimal: 04\t Binary: 0100");
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], LOW);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_05() {
  Serial.println("Decimal: 05\t Binary: 0101");
  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], LOW);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_06() {
  Serial.println("Decimal: 06\t Binary: 0110");
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], LOW);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_07() {
  Serial.println("Decimal: 07\t Binary: 0111");
  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], LOW);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_08() {
  Serial.println("Decimal: 08\t Binary: 1000");
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], HIGH);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_09() {
  Serial.println("Decimal: 09\t Binary: 1001");
  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], HIGH);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_10() {
  Serial.println("Decimal: 10\t Binary: 1010");
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], HIGH);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_11() {
  Serial.println("Decimal: 11\t Binary: 1011");
  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], LOW);
  digitalWrite(ledPins[3], HIGH);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_12() {
  Serial.println("Decimal: 12\t Binary: 1100");
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], HIGH);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_13() {
  Serial.println("Decimal: 13\t Binary: 1101");
  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], LOW);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], HIGH);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_14() {
  Serial.println("Decimal: 14\t Binary: 1110");
  digitalWrite(ledPins[0], LOW);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], HIGH);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}

void count_15() {
  Serial.println("Decimal: 15\t Binary: 1111");
  digitalWrite(ledPins[0], HIGH);
  digitalWrite(ledPins[1], HIGH);
  digitalWrite(ledPins[2], HIGH);
  digitalWrite(ledPins[3], HIGH);
  delay(time_delay);
  digitalWrite(ledPins[0 - 3], LOW);
}
