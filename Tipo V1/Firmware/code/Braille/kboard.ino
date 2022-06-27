char convert(byte keys) {
  for (int i = 0; i <= 54; i += 2) {
    if (keyMap[i] == keys)
      return keyMap[i - 1];
  }
  return 0;
}

char readKeys() {
  byte keys = waitForRelease();
  char c = convert(keys);
  if (debug)Serial.println(c);
  if (c != '#')
    return c;
  //handle numbers
  newPress = 0;
  keys = waitForRelease();
  c = convert(keys) - 16;//ascii conversion from A to 1, B to 2 etc
  if (c == 58) c = '0'; //0 after 9 not before 1 in braille alphabet
  if (debug)Serial.println(c);
  return c;

}


// Function that reads the pressed button values and stores them in a variable. only if button is pressed and released
//would it return a value
byte waitForRelease() {
  byte a = B000000; //initial value
  byte x = B000000; //initial value
  while (1) {  //run in a loop
    x = 0; //reset back to zero after every loop
    for (int i = 0; i < 6; i++) { //read all charecter buttons in a sequence
      if (digitalRead(pinMap[i]) == LOW) { //Button is pressed
        //Enter 1 in the apropriate position for each charter button combination in the byte
        x = 1;
        x <<= i; //bitshift left https://www.arduino.cc/reference/en/language/structure/bitwise-operators/bitshiftleft/
        a = a | x; //Bitwise or https://www.arduino.cc/reference/en/language/structure/bitwise-operators/bitwiseor/
        delay(bouncetime);
        if (debug)Serial.println(a, BIN);
      }
    }
    if (a && !newPress)  //after for loop, 'a' has some value, , new newPress = 1 to indicate a new charecter is available
      newPress = 1;
    if (!x && newPress) //only when X goes back to 0, release the last known values of a, but untill then keep updating a
    {
      delay(3* bouncetime);
      return a;
    }
    if (!a) //if none of the character buttons were pressed
      FnKeys();
  }
}



void FnKeys() {
  byte buttons = 0; // B00(0) - nothing pressed, B01(1) - ent pressed, B10(2) - delete pressed, B11(3) - both pressed
  if (digitalRead(pinMap[6]) == LOW || digitalRead(pinMap[7]) == LOW) {
    delay(bouncetime/2);
    while(digitalRead(pinMap[6]) == LOW || digitalRead(pinMap[7]) == LOW){
      if (digitalRead(pinMap[6]) == LOW)
        buttons |= 1;
      if (digitalRead(pinMap[7]) == LOW)
        buttons |= 2;
    }
//    if (mode == usb) {
//      switch (buttons) {
//        case 1:   Keyboard.press(KEY_RETURN);
//          break;
//        case 2:   Keyboard.press(KEY_BACKSPACE);
//          break;
//        case 3:   Keyboard.write(' ');
//          break;
//      }
      while (digitalRead(pinMap[7]) == LOW || digitalRead(pinMap[6]) == LOW);
      //Keyboard.releaseAll();
      delay(bouncetime/2);
    }
      Serial.print("FnButtons: ");
      Serial.println(buttons);

}
