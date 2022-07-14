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

bool symbolFunction(byte buttonState){
    for (int i = 0; i < symbolMapArrayLength - 2; i += 3) {
        if ((symbolMap[i] == prevInput) && (symbolMap[i+1] == buttonState)){
          bleKeyboard.write(char(symbolMap[i + 2]));
          prevInput = 0;
          symbolFlag = false;
        if (grade1LetterFlag)
          grade1LetterFlag = false;
        if (capitalLetterFlag)
          capitalLetterFlag = false;
        return true;
        }
  }
  symbolFlag = false; //no symbol was detected, turn off flag
  return false;
}

bool numberFunction(byte buttonState) {
  for (int i = 0; i < numMapArrayLength - 1; i += 2) {
    if (numMap[i] == buttonState) {
      //Serial.print(char(numMap[i + 1]));
      bleKeyboard.write(char(numMap[i + 1]));
      prevInput = 0;
      inputBeforePrevInput = 0;
      return true;
    }
  }
  return false;
}


bool grade1CharFunction(byte buttonState) {
  for (int i = 0; i < grade1CharMapArrayLength - 1; i += 2) {
    if (grade1CharMap[i] == buttonState) {
      //Serial.print(char(grade1CharMap[i + 1]));
      if((capitalLetterFlag || capitalWordFlag || capitalLockFlag == true)){
        bleKeyboard.write(toupper(char(grade1CharMap[i + 1])));
        typedWord.concat(toupper(char(grade1CharMap[i + 1])));
        if (capitalLetterFlag)
         capitalLetterFlag = false;
      }
      else{
        bleKeyboard.write(char(grade1CharMap[i + 1]));
        typedWord.concat(char(grade1CharMap[i + 1]));
      }
      prevInput = 0;
      inputBeforePrevInput = 0;
      if (grade1LetterFlag)
        grade1LetterFlag = false;
      return true;
    }
  }
  return false;
}

bool strongContractionsFunction(byte buttonState) {
  /*
  * Rules of Unified English Braille 10.3.
  * Use the strong contraction wherever the letters it 
  * represents occur unless other rules limit its use.
  */
  for (int i = 0; i < strongContractionsMapArrayLength - 1; i += 2) {
    if (strtol(strongContractionsMap[i],NULL,2) == buttonState) {
        if((capitalLetterFlag == true)){
          String word = String(strongContractionsMap[i + 1]);
          word[0] = toupper(word[0]);
          bleKeyboard.print(word);
          capitalLetterFlag = false;
        }
        else if (capitalWordFlag || capitalLockFlag == true){
          String word = String(strongContractionsMap[i + 1]);
          word.toUpperCase();
          bleKeyboard.print(word);
        }
        else
          bleKeyboard.print((strongContractionsMap[i + 1]));
      inputBeforePrevInput = 0;
      prevInput = 0;
      if (grade1LetterFlag)
        grade1LetterFlag = false;
      return true;
    }
  }
  return false; 
}


bool strongGroupsignsFunction(byte buttonState) {
  /*
  * Rules of Unified English Braille 10.2.1 
  * Use the strong wordsign when the word it represents is "standing alone".
  */
  for (int i = 0; i < strongGroupsignsMapArrayLength - 1; i += 2) {
    if (strtol(strongGroupsignsMap[i],NULL,2) == buttonState) {
        if((capitalLetterFlag == true)){
          String word = String(strongGroupsignsMap[i + 1]);
          word[0] = toupper(word[0]);
          bleKeyboard.print(word);
          capitalLetterFlag = false;
        }
        else if (capitalWordFlag || capitalLockFlag == true){
          String word = String(strongGroupsignsMap[i + 1]);
          word.toUpperCase();
          bleKeyboard.print(word);
        }
        else
          bleKeyboard.print((strongGroupsignsMap[i + 1]));
      inputBeforePrevInput = 0;
      prevInput = 0;
      if (grade1LetterFlag)
        grade1LetterFlag = false;
      return true;
    }
  }
  return false; 
}


void isContraction(){
  if (typedWord.length() == 1){//Alphabetic Wordsigns
      for (int i = 0; i < alphabeticWordsignsMapArrayLength - 1; i += 2) {
        if (typedWord.equalsIgnoreCase(String(alphabeticWordsignsMap[i]))) {
            bleKeyboard.write(KEY_BACKSPACE);
            if((!isLowerCase(typedWord[0]))){
              String word = String(alphabeticWordsignsMap[i + 1]);
              word[0] = toupper(word[0]);
              bleKeyboard.print(word);
            }
            else if (capitalWordFlag || capitalLockFlag == true){
              String word = String(alphabeticWordsignsMap[i + 1]);
              word.toUpperCase();
              bleKeyboard.print(word);
            }
            else
              bleKeyboard.print((alphabeticWordsignsMap[i + 1]));
          inputBeforePrevInput = 0;
          prevInput = 0;
          if (grade1LetterFlag)
            grade1LetterFlag = false;
          typedWord = "";
          return;
        }
      }
  }
  typedWord = ""; 
}

void processBrailleButtonState(buttonInfo brailleButton) {


  if (brailleButton.state == INDICATOR_NUMBER) {
    numberIndicatorFunction();
    return;
  }
  if (brailleButton.state == INDICATOR_GRADE_1) {
    grade1IndicatorFunction();
    symbolIndicatorFunction(brailleButton.state); //the Grade 1 symbol indicator is also a symbol for final letter groupsigns. 
    return;
  }

  if (brailleButton.state == INDICATOR_CAPITAL) {
    capitalIndicatorFunction();
    symbolIndicatorFunction(brailleButton.state); //the Capital indicator is also a symbol for final letter groupsigns. 
    return;
  }
  if ((brailleButton.state & B111000) == B000000) {
    symbolIndicatorFunction(brailleButton.state);
    return;
  }

  if (brailleButton.state == INDICATOR_TERMINATOR && (prevInput == INDICATOR_GRADE_1 || prevInput == INDICATOR_CAPITAL)) {
    terminatorIndicatorFunction();
    return;
  }
  //No indicators were pressed, check other button maps
  if(symbolFlag == true){
    if (symbolFunction(brailleButton.state)) //will return false if no symbol was found
      return; //if symbol found, return, or else continue matching
  }

  if (numberFlag == true) {
    if (numberFunction(brailleButton.state));
      return;
  }

  if(grade1CharFunction(brailleButton.state))
    return;

  if (strongContractionsFunction(brailleButton.state))
    return;


}

void processFunctionButtonState(buttonInfo button) {

  if ((button.state & SPACE) == SPACE) {
    isContraction();
    bleKeyboard.press(' ');
    numberFlag = false;
    capitalWordFlag = false;
    grade1WordFlag = false;
    symbolFlag = false;
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


