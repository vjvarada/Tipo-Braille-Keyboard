byte braillePinMap[] = {BTN6 , BTN5, BTN4, BTN3, BTN2, BTN1};
byte functionPinMap[] = {CNT , UP, DWN, LFT, RGT, BTN11, BTN10, BTN9, BTN8, BTN7};

bool brailleButtonHeldFlag = false;
bool functionButtonHeldFlag = false;
unsigned long brailleButtonpressedTime = 0;
unsigned long functionButtonPressedTime = 0;


struct buttonInfo {
  word state;
  unsigned long holdTime;
};


bool isBrailleButtonPressed() {
  for (int i = 0; i < braillePinMapArrayLength; i++)
  {
    if (digitalRead(braillePinMap[i]) == LOW) {
      if (brailleButtonHeldFlag == false) {
        brailleButtonpressedTime = millis();
        brailleButtonHeldFlag = true;
      }
      return true;
    }
  }
  brailleButtonHeldFlag = false;
  return false;
}

bool isFunctionKeyPressed() {
  for (int i = 0; i < functionPinMapArrayLength; i++)
  {
    if (digitalRead(functionPinMap[i]) == LOW) {
      if (functionButtonHeldFlag == false) {
        functionButtonPressedTime = millis();
        functionButtonHeldFlag = true;
      }
      return true;
    }
  }
  functionButtonHeldFlag = false;
  bleKeyboard.releaseAll();
  return false;
}


/*
Function blocks code operation till braille buttons are released
*/
void waitForBrailleButtonRelease(){
  while (isBrailleButtonPressed()) {
  delay(50);
  } 
}

/*
  Function that reads the combination of pressed buttons.Only if a button is pressed and
  subsequently released would the function return a value, as well as the time that the button(s) were held.
  input: None
  Returns: struct buttonInfo, with the braille button states and hold time,
  with value of button 1 at MSB and 6 at LSB
*/
buttonInfo getbrailleButtonState() {
  buttonInfo buttons;
  buttons.state = 0b0;
  buttons.holdTime = 0 ;
  while (isBrailleButtonPressed()) {

    for (int i = 0; i < braillePinMapArrayLength; i++) {
      if (digitalRead(braillePinMap[i]) == LOW)
        buttons.state = buttons.state | 1 << i;
    }
    if  ((millis() - brailleButtonpressedTime) > longPressTime)
      break;
  }
  if (buttons.state > 0) {
    buttons.holdTime = millis() - brailleButtonpressedTime;
    return buttons;
  }
}


/*
  Function that reads the combination of function pressed function buttons and the duration the buttons are being held and
  reports it continuously
  input: None
  Returns: struct buttonInfo, with the function button states and the time they are held
*/
buttonInfo getFunctionButtonState() {
  buttonInfo buttons;
  buttons.state = 0b0;
  buttons.holdTime = 0 ;

  for (int i = 0; i < functionPinMapArrayLength; i++) {
    if (digitalRead(functionPinMap[i]) == LOW)
      buttons.state = buttons.state | 1 << i;
  }
  if (buttons.state > 0) {
    buttons.holdTime = millis() - functionButtonPressedTime;
    return buttons;
  }
}
