  byte buttonStates = B00000000 //Variable that will store value of all button states
  byte buttonState = B00000000 //variable that will momentarily store value of a single button stare

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

word readCharPins() {
  buttonStates = B00000000 //reset button states
  if (digitalRead(BTN1) == LOW)
  {
  	buttonState = B0000000000000001 << 15
  }
}
