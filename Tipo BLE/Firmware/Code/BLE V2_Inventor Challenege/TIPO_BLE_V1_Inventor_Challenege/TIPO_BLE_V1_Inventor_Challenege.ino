
#include <BleKeyboard.h> //https://github.com/T-vK/ESP32-BLE-Keyboard
BleKeyboard  bleKeyboard(" BraillePad", "Vijay", 100);

#include "pins.h"
#include "readButtons.h"
#include "grade1Braille.h"
#include "grade2Braille.h"
#include "shortcuts.h"
#include "processButtons.h"

void setup() {
  for (int i = 0; i < braillePinMapArrayLength; i++)
  {
    pinMode(braillePinMap[i], INPUT_PULLUP);
  }
  for (int i = 0; i < functionPinMapArrayLength; i++)
  {
    pinMode(functionPinMap[i], INPUT_PULLUP);
  }
  pinMode(vibrationMotor, OUTPUT);
  pinMode(statusLED, OUTPUT);
  digitalWrite(statusLED, HIGH);
  digitalWrite(vibrationMotor, HIGH);
  delay(50);
  digitalWrite(vibrationMotor, LOW);
  digitalWrite(statusLED, LOW);

  Serial.begin(115200);
  bleKeyboard.begin();
}


void loop() {
  if (bleKeyboard.isConnected()) {
    if (isBrailleButtonPressed())
      processBrailleButtonState(getbrailleButtonState());
    if (isFunctionKeyPressed())
      processFunctionButtonState(getFunctionButtonState());
    Serial.println(typedWord);
    delay(bounceTime);
  }
}


/*
TO DO
Shortcuts
end contractions
lower wordsigs ard groupsigns
battery level vibration
battery level to phone
BT pair mode on/off
*/