//Write a program to check the position of the rotary selector switch connected to pins 0 to 3 on Port C
//Turn on all green LEDs if the rotary selector switch is at position 1
//Blink LED4 if the selector is at position 2
//Turn off all green LEDs if the rotary selector switch is at other positions

void setup() {
  // put your setup code here, to run once:
  DDRC &= B11110000; // Set outputs by clearing bits with &=
  DDRL |= B11110111; // Set inputs by setting bits with |=
  DDRG |= B00001000;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(SelectorPosition() == 1) {
    PORTL &= B00001000;
    PORTG &= B11110111;
  }
  else if (SelectorPosition() ==2) {
    greenLEDon(4);
    delay(1000);
    greenLEDoff(4);
    delay(1000);
  }
  else{
    PORTL |= ~B11110111;
    PORTG |= ~B00001000;
  }
}

unsigned char SelectorPosition() {
  return PINC & 0x0F; // xxxxxxxx & 00001111
}
void greenLEDon(unsigned char LEDno) { //Create this function to turn LEDno ON
  if(LEDno ==4) {
    PORTG |= (1<<LEDno);  
  }
  else{
    PORTL |= (1<<LEDno);
  }
}

void greenLEDoff(unsigned char LEDno){ // Create this function to turn LEDno OFF
  if(LEDno ==4) {
     PORTG &= ~(1<<LEDno);  
  }
  else{
    PORTL &= ~(1<<LEDno);
  }
  }
