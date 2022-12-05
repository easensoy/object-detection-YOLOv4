//Using direct port manipulation, write a program to create blinking LED connected at PL1 (LED1).
unsigned char LEDno = 1; 
void setup() {
  // put your setup code here, to run once:
  DDRL |= (1<<LEDno); //00000010 --> bit shift
}

void loop() {
  // put your main code here, to run repeatedly:
  greenLEDon(LEDno); // call your greenLEDon function here
  delay(1000);
  greenLEDoff(LEDno); // call your greenLEDoff function here
  delay(1000);
}
void greenLEDon(unsigned char LEDno) { //Create this function to turn LEDno ON
  PORTL |= (1<<LEDno);  
}

void greenLEDoff(unsigned char LEDno){ // Create this function to turn LEDno OFF
  PORTL &= ~(1<<LEDno); //00000000 & 11111101 = 00000010
}
