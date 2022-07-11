bool numberFlag = false ;
bool capitalLetterFlag = false ;
bool capitalWordFlag = false ;
bool capitalLockFlag = false ;
bool grade1LetterFlag = false ;
bool grade1WordFlag = false ;
bool grade1LockFlag = false ;
bool symbolFlag = false ;
byte prevInput = 0b0;
byte inputBeforePrevInput = 0b0;
String typedWord = "";



void numberIndicatorFunction() {
  numberFlag = true;
}

void grade1IndicatorFunction() {
  if (prevInput == INDICATOR_GRADE_1 && inputBeforePrevInput == INDICATOR_GRADE_1) {
    inputBeforePrevInput = INDICATOR_GRADE_1;
    grade1LetterFlag = false;
    grade1WordFlag = false;
    grade1LockFlag = true;
    //Serial.println("Grade 1 lock");
  }
  else if (prevInput == INDICATOR_GRADE_1) {
    inputBeforePrevInput = INDICATOR_GRADE_1; inputBeforePrevInput = 0;
    grade1LetterFlag = false;
    grade1WordFlag = true;
    //Serial.println("Grade 1 Word");
  }

  else {
    grade1LetterFlag = true;
    numberFlag = false;
    prevInput = INDICATOR_GRADE_1;
    //Serial.println("Grade 1 Letter");
  }
}

void capitalIndicatorFunction() {
  if (prevInput == INDICATOR_CAPITAL && inputBeforePrevInput == INDICATOR_CAPITAL) {
    inputBeforePrevInput = INDICATOR_CAPITAL;
    capitalLetterFlag = false;
    capitalWordFlag = false;
    capitalLockFlag = true;
    //Serial.println("Capital lock");
  }

  else if (prevInput == INDICATOR_CAPITAL) {
    inputBeforePrevInput = INDICATOR_CAPITAL;
    capitalLetterFlag = false;
    capitalWordFlag = true;
    //Serial.println("Capital Word");
  }

  else {
    capitalLetterFlag = true;
    prevInput = INDICATOR_CAPITAL;
    //Serial.println("Capital Letter");
  }
}

void symbolIndicatorFunction(byte buttonState) {
  symbolFlag = true;
  prevInput = buttonState;
  Serial.println("Some Symbol was pressed");
}

void terminatorIndicatorFunction() {
  if (prevInput == INDICATOR_GRADE_1) {
    grade1LetterFlag = false;
    grade1WordFlag = false;
    grade1LockFlag = false;
    //Serial.println("Grade 1 Terminated");
    prevInput = 0b0;
  }
  else if (prevInput == INDICATOR_CAPITAL) {
    capitalLetterFlag = false;
    capitalWordFlag = false;
    capitalLockFlag = false;
    //Serial.println("Capitals 1 Terminated");
    prevInput = 0b0;
  }
}

void numberFunction(byte buttonState) {
  for (int i = 0; i < grade1NumMapArrayLength - 1; i += 2) {
    if (grade1NumMap[i] == buttonState) {
      //Serial.print(char(grade1NumMap[i + 1]));
      bleKeyboard.write(char(grade1NumMap[i + 1]));
      prevInput = 0;
      inputBeforePrevInput = 0;
    }
  }
}

void capitalCharFunction(byte buttonState) {
  for (int i = 0; i < grade1CapCharMapArrayLength - 1; i += 2) {
    if (grade1CapCharMap[i] == buttonState) {
      //Serial.print(char(grade1CapCharMap[i + 1]));
      bleKeyboard.write(char(grade1CapCharMap[i + 1]));
      prevInput = 0;
      inputBeforePrevInput = 0;
      if (capitalLetterFlag)
        capitalLetterFlag = false;
    }
  }
}

void grade1CharFunction(byte buttonState) {
  for (int i = 0; i < grade1CharMapArrayLength - 1; i += 2) {
    if (grade1CharMap[i] == buttonState) {
      //Serial.print(char(grade1CharMap[i + 1]));
      bleKeyboard.write(char(grade1CharMap[i + 1]));
      inputBeforePrevInput = 0;
      prevInput = 0;
    }
  }
}

void processBrailleButtonState(buttonInfo brailleButton) {

  if (brailleButton.state == INDICATOR_NUMBER) {
    numberIndicatorFunction();
    return;
  }
  else if (brailleButton.state == INDICATOR_GRADE_1) {
    grade1IndicatorFunction();
    return;
  }

  else if (brailleButton.state == INDICATOR_CAPITAL) {
    capitalIndicatorFunction();
    return;
  }
  else if ((brailleButton.state & B111000) == B000000) {
    symbolIndicatorFunction(brailleButton.state);
    return;
  }

  else if (brailleButton.state == INDICATOR_TERMINATOR && (prevInput == INDICATOR_GRADE_1 || prevInput == INDICATOR_CAPITAL)) {
    terminatorIndicatorFunction();
    return;
  }

  //No indicators were pressed, check other button maps

  if (numberFlag == true) {
    numberFunction(brailleButton.state);
  }
  else if (capitalLetterFlag || capitalWordFlag || capitalLockFlag == true) {
    capitalCharFunction(brailleButton.state);
  }
  else
    grade1CharFunction(brailleButton.state);

}

void processFunctionButtonState(buttonInfo button) {

  if ((button.state & SPACE) == SPACE) {
    bleKeyboard.press(' ');
    numberFlag = false;
    capitalWordFlag = false;
    grade1WordFlag = false;
  }
  else
    bleKeyboard.release(' ');
  if ((button.state & CENTER) == CENTER)
    bleKeyboard.press(KEY_RETURN);
  else
    bleKeyboard.release(KEY_RETURN);
  if ((button.state & BACKSPACE) == BACKSPACE)
    bleKeyboard.press(KEY_BACKSPACE);
  else
    bleKeyboard.release(KEY_BACKSPACE);
  if ((button.state & UP) == UP)
    bleKeyboard.press(KEY_UP_ARROW);
  else
    bleKeyboard.release(KEY_UP_ARROW);
  if ((button.state & DOWN) == DOWN)
    bleKeyboard.press(KEY_PAGE_DOWN);
  else
    bleKeyboard.release(KEY_PAGE_DOWN);
  if ((button.state & LEFT) == LEFT)
    bleKeyboard.press(KEY_LEFT_ARROW);
  else
    bleKeyboard.release(KEY_LEFT_ARROW);
  if ((button.state & RIGHT) == RIGHT)
    bleKeyboard.press(KEY_RIGHT_ARROW);
  else
    bleKeyboard.release(KEY_RIGHT_ARROW);
  if ((button.state & CONTROL) == CONTROL)
    bleKeyboard.press(KEY_LEFT_CTRL);
  else
    bleKeyboard.release(KEY_LEFT_CTRL);
  if ((button.state & SHIFT) == SHIFT)
    bleKeyboard.press(KEY_LEFT_SHIFT);
  else
    bleKeyboard.release(KEY_LEFT_SHIFT);
//  if ((button.state & ALT) == ALT)
//    bleKeyboard.press(KEY_LEFT_ALT);
//  else
//    bleKeyboard.release(KEY_LEFT_ALT);
}
