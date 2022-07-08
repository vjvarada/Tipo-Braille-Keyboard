#include "pins.h"

int bouncetime = 50;
bool brailleButtonHeldFlag = false;
bool functionButtonHeldFlag = false;
unsigned long brailleButtonpressedTime = 0;
unsigned long functionButtonPressedTime = 0;

byte brailleButtonPinMap[] = {BTN6 , BTN5, BTN4, BTN3, BTN2, BTN1};
byte functionButtonPinMap[] = {CNT , UP, DWN, LFT, RGT, BTN10, BTN9, BTN8, BTN7};


struct buttonInfo {
  word state;
  unsigned long holdTime;
};


bool isBrailleButtonPressed() {
  for (int i = 0; i < 6; i++)
  {
    if (digitalRead(brailleButtonPinMap[i]) == LOW)
      return true;
  }
  brailleButtonHeldFlag = false;
  return false;
}

bool isFunctionKeyPressed() {
  for (int i = 0; i < 9; i++)
  {
    if (digitalRead(functionButtonPinMap[i]) == LOW)
      return true;
  }
  functionButtonHeldFlag = false;
  return false;
}

/*
  Function that reads the combination of pressed buttons.Only if a button is pressed and
  subsequently released would the function return a value, as well as the time that the button(s) were held.
  input: None
  Returns: struct buttonInfo, with the braille button states and hold time,
  with value of button 1 at MSB and 6 at LSB
*/
buttonInfo getbrailleButtonInfo() {
  buttonInfo buttons;
  buttons.state = 0b0;
  buttons.holdTime = 0 ;
  while (isBrailleButtonPressed()) {
    if (brailleButtonHeldFlag == false) {
      brailleButtonpressedTime = millis();
      brailleButtonHeldFlag = true;
    }
    for (int i = 0; i < 6; i++) {
      if (digitalRead(brailleButtonPinMap[i]) == LOW)
        buttons.state = buttons.state | 1 << i;
    }
  }
  if (buttons.state > 0) {
    buttons.holdTime = millis() - brailleButtonpressedTime;
    return buttons;
  }
}



buttonInfo getFunctionButtonState() {
  buttonInfo buttons;
  buttons.state = 0b0;
  buttons.holdTime = 0 ;
  if (functionButtonHeldFlag == false) {
    functionButtonPressedTime = millis();
    functionButtonHeldFlag = true;
  }
  for (int i = 0; i < 9; i++) {
    if (digitalRead(functionButtonPinMap[i]) == LOW)
      buttons.state = buttons.state | 1 << i;
  }
  if (buttons.state > 0) {
    buttons.holdTime = millis() - functionButtonPressedTime;
    return buttons;
  }
}




void processBrailleButtonState(buttonInfo brailleButton) {
  Serial.println();
  Serial.print("Braille Button States: ");
  Serial.print(brailleButton.state, BIN);
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
