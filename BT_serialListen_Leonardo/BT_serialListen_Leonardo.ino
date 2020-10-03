int number = 1;

void setup() {
  // put your setup code here, to run once:
  Serial1.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly: 
  Serial1.print("Loop nr: ");
  Serial1.print(number++);
  Serial1.println("");
  delay(1000);
}
