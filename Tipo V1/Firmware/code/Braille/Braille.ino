//#include "Keyboard.h"
#define mode serial
#define debug 1
#define bouncetime 50
enum modes {serial, usb};
bool newPress;
//               s6,s5,s4,s3,s2,s1,ENT,DEL
byte pinMap[] = {27 , 36, 19, 14, 25, 22, 13, 12 };
byte keyMap[] = {

  B000000,
  'A', B00100000,//a
  'B', B00110000,
  'C', B00100100,
  'D', B00100110,
  'E', B00100010,
  'F', B00110100,
  'G', B00110110,//s
  'H', B00110010,
  'I', B00010100,
  'J', B00010110,
  'K', B00101000,
  'L', B00111000,
  'M', B00101100,
  'N', B00101110,
  'O', B00101010,
  'P', B00111100,
  'Q', B00111110,
  'R', B00111010,
  'S', B00011100,
  'T', B00011110,
  'U', B00101001,
  'V', B00111001,
  'W', B00010111,
  'X', B00101101,
  'Y', B00101111,
  'Z', B00101011, //z
  '#', B00001111,
};

void setup() {
  if (debug)
    Serial.begin(115200);
//  if (mode == usb)
//    Keyboard.begin();
  for (int i = 0; i <= 7; i++) {
    pinMode(pinMap[i], INPUT);
    digitalWrite(pinMap[i], HIGH);
  }
}

void loop() {
  char character = readKeys();

  if (newPress && character != 0) {
//    if (mode == usb)
//      Keyboard.print(character);
//    else if (mode == serial)
      Serial.print(character);
    newPress = 0;
  }
  
  if (newPress) newPress = 0;
}
