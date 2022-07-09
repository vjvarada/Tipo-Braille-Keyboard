#include "pins.h"
#include "readButtons.h"
#include "grade1Braille.h"
#include "grade2Braille.h"
#include "shortcuts.h"
#include "processButtons.h"







void setup() {
  for (int i = 0; i < 6; i++)
  {
    pinMode(brailleButtonPinMap[i], INPUT_PULLUP);
  }
  for (int i = 0; i < 9; i++)
  {
    pinMode(functionButtonPinMap[i], INPUT_PULLUP);
  }
  Serial.begin(115200);
}


void loop() {
  if (isBrailleButtonPressed())
    processBrailleButtonState(getbrailleButtonInfo());
  if (isFunctionKeyPressed())
    processFunctionButtonState(getFunctionButtonState());
  delay(bouncetime);
}
