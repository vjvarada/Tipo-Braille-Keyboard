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


void isContraction() {
  /*
    Function that checks if the word stored in the buffer "typesWord" is a contraction.
    this shoulc be called when the "Standing Alone" rules of UEB of space, symbols come up
  */
  if (typedWord.equalsIgnoreCase(String("en")) && prevInput == 0b101110 && inputBeforePrevInput == 0b100010 ) {
    // when which are brailled individually should not trigger a contraction, use a conditional statement like this
    typedWord = "";
    inputBeforePrevInput = 0;
    prevInput = 0;
    return;
  }
  else if (typedWord.length() == 1) { //Alphabetic Wordsigns
    for (int i = 0; i < alphabeticWordsignsMapArrayLength - 1; i += 2) {
      if (typedWord.equalsIgnoreCase(String(alphabeticWordsignsMap[i]))) {
        bleKeyboard.write(KEY_BACKSPACE);
        if (capitalWordFlag || capitalLockFlag == true) {
          String word = String(alphabeticWordsignsMap[i + 1]);
          word.toUpperCase();
          bleKeyboard.print(word);
        }
        else if ((!isLowerCase(typedWord[0]))) {
          String word = String(alphabeticWordsignsMap[i + 1]);
          word[0] = toupper(word[0]);
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
  else if (typedWord.length() > 1) { //shortformWords
    for (int i = 0; i < shortformWordsMapArrayLength - 1; i += 2) {
      if (typedWord.equalsIgnoreCase(String(shortformWordsMap[i]))) {
        for (int j = 0; j < typedWord.length(); j++) {
          bleKeyboard.write(KEY_BACKSPACE);
        }
        if (capitalWordFlag || capitalLockFlag == true) {
          String word = String(shortformWordsMap[i + 1]);
          word.toUpperCase();
          bleKeyboard.print(word);
        }
        else if ((!isLowerCase(typedWord[0]))) {
          String word = String(shortformWordsMap[i + 1]);
          word[0] = toupper(word[0]);
          bleKeyboard.print(word);
        }

        else
          bleKeyboard.print((shortformWordsMap[i + 1]));
        inputBeforePrevInput = 0;
        prevInput = 0;
        if (grade1LetterFlag)
          grade1LetterFlag = false;
        typedWord = "";
        return;
      }
    }
    for (int i = 0; i < strongWordsignsMapArrayLength - 1; i += 2) {
      if (typedWord.equalsIgnoreCase(String(strongWordsignsMap[i]))) {
        for (int j = 0; j < typedWord.length(); j++) {
          bleKeyboard.write(KEY_BACKSPACE);
        }
        if (capitalWordFlag || capitalLockFlag == true) {
          String word = String(strongWordsignsMap[i + 1]);
          word.toUpperCase();
          bleKeyboard.print(word);
        }
        else if ((!isLowerCase(typedWord[0]))) {
          String word = String(strongWordsignsMap[i + 1]);
          word[0] = toupper(word[0]);
          bleKeyboard.print(word);
        }

        else
          bleKeyboard.print((strongWordsignsMap[i + 1]));
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
  inputBeforePrevInput = 0;
  prevInput = 0;
}

void numberIndicatorFunction() {
  numberFlag = true;
  digitalWrite(vibrationMotor, HIGH);
  delay(50);
  digitalWrite(vibrationMotor, LOW);
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
    inputBeforePrevInput = INDICATOR_GRADE_1;
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
  digitalWrite(vibrationMotor, HIGH);
  delay(50);
  digitalWrite(vibrationMotor, LOW);
}

void terminatorIndicatorFunction() {
  if (prevInput == INDICATOR_GRADE_1) {
    grade1LetterFlag = false;
    grade1WordFlag = false;
    grade1LockFlag = false;
    //Serial.println("Grade 1 Terminated");
    prevInput = 0b0;
    inputBeforePrevInput = 0;
  }
  else if (prevInput == INDICATOR_CAPITAL) {
    capitalLetterFlag = false;
    capitalWordFlag = false;
    capitalLockFlag = false;
    //Serial.println("Capitals 1 Terminated");
    prevInput = 0b0;
    inputBeforePrevInput = 0;
  }
  digitalWrite(vibrationMotor, HIGH);
  delay(50);
  digitalWrite(vibrationMotor, LOW);
}

bool symbolFunction(byte buttonState) {
  for (int i = 0; i < symbolMapArrayLength - 2; i += 3) {
    if ((symbolMap[i] == prevInput) && (symbolMap[i + 1] == buttonState)) {
      bleKeyboard.write(char(symbolMap[i + 2]));
      if (!(grade1LetterFlag || grade1WordFlag || grade1LockFlag)) {
        isContraction();
        typedWord = "symbol"; //so that contraction isnt entered by mistake next time, eg xx's
      }
      prevInput = 0;
      inputBeforePrevInput = 0;
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
      if ((capitalLetterFlag || capitalWordFlag || capitalLockFlag == true)) {
        bleKeyboard.write(toupper(char(grade1CharMap[i + 1])));
        if (!(grade1LetterFlag || grade1WordFlag || grade1LockFlag))
          typedWord.concat(char(toupper(char(grade1CharMap[i + 1]))));
        if (capitalLetterFlag)
          capitalLetterFlag = false;
      }
      else {
        bleKeyboard.write(char(grade1CharMap[i + 1]));
        if (!(grade1LetterFlag || grade1WordFlag || grade1LockFlag))
          typedWord.concat(char(grade1CharMap[i + 1]));
      }
      inputBeforePrevInput = prevInput;
      prevInput = buttonState;
      if (grade1LetterFlag)
        grade1LetterFlag = false;
      return true;
    }
  }
  return false;
}

bool grade1PunctuationFunction(byte buttonState) {
  for (int i = 0; i < grade1PunctuationMapArrayLength - 1; i += 2) {
    if (grade1PunctuationMap[i] == buttonState) {
      if (!(grade1LetterFlag || grade1WordFlag || grade1LockFlag)) {
        isContraction();
        typedWord = "symbol"; //so that contraction isnt entered by mistake next time, eg xx's
      }
      bleKeyboard.write(char(grade1PunctuationMap[i + 1]));
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
    and,for,the...
    Rules of Unified English Braille 10.3.
    Use the strong contraction wherever the letters it
    represents occur unless other rules limit its use.
  */
  for (int i = 0; i < strongContractionsMapArrayLength - 1; i += 2) {
    if (strtol(strongContractionsMap[i], NULL, 2) == buttonState) {
      if ((capitalLetterFlag == true)) {
        String word = String(strongContractionsMap[i + 1]);
        word[0] = toupper(word[0]);
        bleKeyboard.print(word);
        capitalLetterFlag = false;
      }
      else if (capitalWordFlag || capitalLockFlag == true) {
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
    ch,sh,st...
    Rules of Unified English Braille 10.2.1
    Use the strong wordsign when the word it represents is "standing alone".
  */
  for (int i = 0; i < strongGroupsignsMapArrayLength - 1; i += 2) {
    if (strtol(strongGroupsignsMap[i], NULL, 2) == buttonState) {
      if ((capitalLetterFlag == true)) {
        String word = String(strongGroupsignsMap[i + 1]);
        word[0] = toupper(word[0]);
        bleKeyboard.print(word);
        typedWord.concat(word);
        capitalLetterFlag = false;
      }
      else if (capitalWordFlag || capitalLockFlag == true) {
        String word = String(strongGroupsignsMap[i + 1]);
        word.toUpperCase();
        bleKeyboard.print(word);
        typedWord.concat(word);
      }
      else {
        bleKeyboard.print((strongGroupsignsMap[i + 1]));
        typedWord.concat((strongGroupsignsMap[i + 1]));
      }

      inputBeforePrevInput = 0;
      prevInput = 0;
      if (grade1LetterFlag)
        grade1LetterFlag = false;
      return true;
    }
  }
  return false;
}

bool initialLetterContractionFunction(byte buttonState) {
  for (int i = 0; i < initialLetterContractionsMapArrayLength - 2; i += 3) {
    if ((strtol(initialLetterContractionsMap[i], NULL, 2) == prevInput) && (strtol(initialLetterContractionsMap[i + 1], NULL, 2) == buttonState)) {

      if ((capitalLetterFlag == true)) {
        String word = String(initialLetterContractionsMap[i + 2]);
        word[0] = toupper(word[0]);
        bleKeyboard.print(word);
        capitalLetterFlag = false;
      }

      else if (capitalWordFlag || capitalLockFlag == true) {
        String word = String(initialLetterContractionsMap[i + 2]);
        word.toUpperCase();
        bleKeyboard.print(word);
      }
      else
        bleKeyboard.print(initialLetterContractionsMap[i + 2]);
      prevInput = 0;
      inputBeforePrevInput = 0;
      symbolFlag = false;
      if (grade1LetterFlag)
        grade1LetterFlag = false;
      return true;
    }
  }
  symbolFlag = false; //no symbol was detected, turn off flag
  return false;
}


bool finalLetterGroupsignsFunction(byte buttonState) {
  for (int i = 0; i < finalLetterGroupsignsMapArrayLength - 2; i += 3) {
    if ((strtol(finalLetterGroupsignsMap[i], NULL, 2) == prevInput) && (strtol(finalLetterGroupsignsMap[i + 1], NULL, 2) == buttonState)) {

      if ((capitalLetterFlag == true)) {
        String word = String(finalLetterGroupsignsMap[i + 2]);
        word[0] = toupper(word[0]);
        bleKeyboard.print(word);
        capitalLetterFlag = false;
        typedWord = "";
      }

      else if (capitalWordFlag || capitalLockFlag == true) {
        String word = String(finalLetterGroupsignsMap[i + 2]);
        word.toUpperCase();
        bleKeyboard.print(word);
        typedWord = "";
      }
      else
        bleKeyboard.print(finalLetterGroupsignsMap[i + 2]);
      prevInput = 0;
      inputBeforePrevInput = 0;
      symbolFlag = false;
      if (grade1LetterFlag)
        grade1LetterFlag = false;
      typedWord = "";
      return true;
    }
  }
  symbolFlag = false; //no symbol was detected, turn off flag
  return false;
}


bool lowerGroupsigns_joining_Function(byte buttonState) {
  /*
    ea,bb,cc...
  */
  for (int i = 0; i < lowerGroupsigns_joining_MapArrayLength - 1; i += 2) {
    if (strtol(lowerGroupsigns_joining_Map[i], NULL, 2) == buttonState) {
      if ((capitalLetterFlag == true)) {
        String word = String(lowerGroupsigns_joining_Map[i + 1]);
        word[0] = toupper(word[0]);
        bleKeyboard.print(word);
        typedWord.concat(word);
        capitalLetterFlag = false;
      }
      else if (capitalWordFlag || capitalLockFlag == true) {
        String word = String(lowerGroupsigns_joining_Map[i + 1]);
        word.toUpperCase();
        bleKeyboard.print(word);
        typedWord.concat(word);
      }
      else {
        bleKeyboard.print((lowerGroupsigns_joining_Map[i + 1]));
        typedWord.concat((lowerGroupsigns_joining_Map[i + 1]));
      }

      inputBeforePrevInput = 0;
      prevInput = 0;
      if (grade1LetterFlag)
        grade1LetterFlag = false;
      return true;
    }
  }
  return false;
}

bool lowerGroupsigns_starting_Function(byte buttonState) {
  /*
    be,con,dis...
  */
  for (int i = 0; i < lowerGroupsigns_starting_MapArrayLength - 1; i += 2) {
    if (strtol(lowerGroupsigns_starting_Map[i], NULL, 2) == buttonState) {
      if ((capitalLetterFlag == true)) {
        String word = String(lowerGroupsigns_starting_Map[i + 1]);
        word[0] = toupper(word[0]);
        bleKeyboard.print(word);
        typedWord.concat(word);
        capitalLetterFlag = false;
      }
      else if (capitalWordFlag || capitalLockFlag == true) {
        String word = String(lowerGroupsigns_starting_Map[i + 1]);
        word.toUpperCase();
        bleKeyboard.print(word);
        typedWord.concat(word);
      }
      else {
        bleKeyboard.print((lowerGroupsigns_starting_Map[i + 1]));
        typedWord.concat((lowerGroupsigns_starting_Map[i + 1]));
      }

      inputBeforePrevInput = 0;
      prevInput = 0;
      if (grade1LetterFlag)
        grade1LetterFlag = false;
      return true;
    }
  }
  return false;
}

void processShortcut(byte buttonState) {
  for (int i = 0; i < grade1CharMapArrayLength - 1; i += 2) {
    if (grade1CharMap[i] == buttonState) {
      switch (char(grade1CharMap[i + 1])) {
        case 'a':
          assistant();
          return;
        case 'b':
          back();
          return;
        case 'c':
          copy();
          return;
        case 'e':
          email();
          return;
        case 'p':
          contacts();
          return;
        case 'm':
          messages();
          return;
        case 'd':
          maps();
          return;
        case 's':
          music();
          return;
        case 'y':
          youTube();
          return;
        case 't':
          calender();
          return;
        case 'x':
          cut();
          return;
        case 'v':
          paste();
          return;
        case 'h':
          home();
          return;
        case 'l':
          appList_selectAll();
          return;
        case 'r':
          recentApps();
          return;
        case 'n':
          notifications();
          return;
        case 'f':
          searchScreen();
          return;
        case 'z':
          pauseResumeTalkBack();
          return;
      //   case 'g':
      //     playPause();
      //     return;
      }
    }
  }
  // for (int i = 0; i < grade1PunctuationMapArrayLength - 1; i += 2) {
  //   if (grade1PunctuationMap[i] == buttonState) {
  //     switch (char(grade1PunctuationMap[i + 1])) {
  //       case '.':
  //         volumeUp();
  //         return;
  //       case '!':
  //         volumeDown();
  //         return;
  //       case '?':
  //         previousTrack();
  //         return;
  //       case '"':
  //         nextTrack();
  //         return;
  //     }
  //   }
  // }
}


void processBrailleButtonState(buttonInfo brailleButton) {


  if (brailleButton.holdTime > longPressTime) {
    digitalWrite(vibrationMotor, HIGH);
    delay(50);
    digitalWrite(vibrationMotor, LOW);
    processShortcut(brailleButton.state);
    waitForBrailleButtonRelease();
  }
  else {
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

    if (symbolFlag == true) {
      if (symbolFunction(brailleButton.state))
        return;
      if (initialLetterContractionFunction(brailleButton.state))
        return;
      if (typedWord.length() >= 1) {
        if (finalLetterGroupsignsFunction(brailleButton.state))
          return;
      }
    }

    if (numberFlag == true) {
      if (numberFunction(brailleButton.state))
        return;
    }

    if (grade1CharFunction(brailleButton.state))
      return;

    if (grade1PunctuationFunction(brailleButton.state))
      return;


    if (!(grade1LetterFlag || grade1WordFlag || grade1LockFlag)) {
      if (strongContractionsFunction(brailleButton.state))
        return;

      if (strongGroupsignsFunction(brailleButton.state))
        return;
      if (typedWord.length() >= 1) {
        if (lowerGroupsigns_joining_Function(brailleButton.state))
          return;
      }
      else
        (lowerGroupsigns_starting_Function(brailleButton.state));
      return;
    }

  }


}

void processFunctionButtonState(buttonInfo button) {

  // Serial.println();
  // Serial.print("0b");
  // Serial.print(button.state,BIN);

  if ((button.state & SPACE) == SPACE) {
    if (!(grade1LetterFlag || grade1WordFlag || grade1LockFlag))
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
  if ((button.state & BACKSPACE) == BACKSPACE) {
    if (button.holdTime < bounceTime)
      typedWord.remove(typedWord.length() - 1);
    else if (button.holdTime > 5 * bounceTime)
      typedWord = "";
    bleKeyboard.press(KEY_BACKSPACE);
  }

  else
    bleKeyboard.release(KEY_BACKSPACE);
  if ((button.state & UP) == UP){
    typedWord = "";
    bleKeyboard.press(KEY_UP_ARROW);
  }
  else
    bleKeyboard.release(KEY_UP_ARROW);
  if ((button.state & DOWN) == DOWN){
    typedWord = "";
    bleKeyboard.press(KEY_DOWN_ARROW);
  }
  else
    bleKeyboard.release(KEY_PAGE_DOWN);
  if ((button.state & LEFT) == LEFT){
    typedWord = "";
    bleKeyboard.press(KEY_LEFT_ARROW);
  }
  else
    bleKeyboard.release(KEY_LEFT_ARROW);
  if ((button.state & RIGHT) == RIGHT){
    typedWord = "";
    bleKeyboard.press(KEY_RIGHT_ARROW);
  }
  else
    bleKeyboard.release(KEY_RIGHT_ARROW);
  if ((button.state & CONTROL) == CONTROL){
    typedWord = "";
    bleKeyboard.press(KEY_LEFT_CTRL);
  }
  else
    bleKeyboard.release(KEY_LEFT_CTRL);
  if ((button.state & SHIFT) == SHIFT)
    bleKeyboard.press(KEY_LEFT_SHIFT);
  else
    bleKeyboard.release(KEY_LEFT_SHIFT);
  if ((button.state & ALT) == ALT)
    bleKeyboard.press(KEY_LEFT_ALT);
  else
    bleKeyboard.release(KEY_LEFT_ALT);

}
