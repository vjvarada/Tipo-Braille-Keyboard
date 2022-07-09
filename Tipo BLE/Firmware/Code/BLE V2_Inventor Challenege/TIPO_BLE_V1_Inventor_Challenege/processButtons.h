bool numberFlag = false ;
bool capitalLetterFlag = false ;
bool capitalWordFlag = false ;
bool capitalLockFlag = false ;
bool grade1Flag = false ;
bool symbolFlag = false ;
String typedWord = "";

char mapBrailleToChar(byte buttons) {
  for (int i = 0; i <= 50; i += 2) {
    if (brailleButtonCharMap[i] == buttons)
      return brailleButtonCharMap[i + 1];
  }
  return 0;
}


void processBrailleButtonState(buttonInfo brailleButton) {
  Serial.println();
  Serial.print("Braille Button States: ");
  Serial.print(brailleButton.state, BIN);
  Serial.print("  Char: ");
  Serial.print(mapBrailleToChar(brailleButton.state));
  Serial.print("  Hold Time: ");
  Serial.print(brailleButton.holdTime);
}
void processFunctionButtonState(buttonInfo brailleButton) {
  Serial.println();
  Serial.print("Function Button States: ");
  Serial.print(brailleButton.state, BIN);
  Serial.print("  Hold Time: ");
  Serial.print(brailleButton.holdTime);
}
