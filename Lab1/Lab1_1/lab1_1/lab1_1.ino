//write a program to create a blinking LED connected at pin 35 (Digital Pin 49 or PL0)
void setup() {
  // put your setup code here, to run once:
  pinMode(49, OUTPUT); //
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(49, HIGH); //setting to voltage of the PIN (HIGH VALUE)
  delay(1000);
  digitalWrite(49, LOW);
  delay(1000);
}
