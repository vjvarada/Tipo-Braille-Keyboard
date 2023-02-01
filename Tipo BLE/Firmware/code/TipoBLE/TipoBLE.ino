
#define DEBUG 1
#include <BleKeyboard.h> //https://github.com/T-vK/ESP32-BLE-Keyboard

BleKeyboard  bleKeyboard("Braille keyboard", "Vijay", 100);

int bouncetime = 50;
//               s6,s5,s4,s3,s2,s1,Space,DEL,Enter,Esc,UP,DOWN,LEFT,RIGHT)
byte pinMap[] = {27 , 26, 19, 14, 25, 22, 13, 12,32,33,15,16,2,4,17};
int arraySize =  (sizeof(pinMap) / sizeof(pinMap[0]));
byte keyMap[] = {
  B000000,
  'a', B00100000,//a
  'b', B00110000,
  'c', B00100100,
  'd', B00100110,
  'e', B00100010,
  'f', B00110100,
  'g', B00110110,
  'h', B00110010,
  'i', B00010100,
  'j', B00010110,
  'k', B00101000,
  'l', B00111000,
  'm', B00101100,
  'n', B00101110,
  'o', B00101010,
  'p', B00111100,
  'q', B00111110,
  'r', B00111010,
  's', B00011100,
  't', B00011110,
  'u', B00101001,
  'v', B00111001,
  'w', B00010111,
  'x', B00101101,
  'y', B00101111,
  'z', B00101011, //z
  '#', B00001111,
  ' ', B00001001,
};

char ch;

/* 
Function that reads the combination of pressed buttons.Only if a button is pressed and
subsequently released would the function return a value.
input: byte array of all the physical pin numbering in the sequence s6,s5,s4,s3,s2,s1,SPACE,DEL
Returns: charecter or function button
*/
byte readKeys() {
  byte fullCharKeyValue = B00000000; //initial value for charecter key combination
  byte singleCharKeyValue = B00000000; //initial value for single button press for charecter key
  byte functionKeyValue = B10000000; //initial value for function key combination
  while (1) {  //run in a loop
    singleCharKeyValue = 0; //reset back to zero after every loop
    for (int i = 0; i < 6; i++) 
    { //read all charecter buttons in a sequence
      if (digitalRead(pinMap[i]) == LOW) 
      {//Enter 1 in the apropriate position for each charter button combination in the byte
        singleCharKeyValue = 1;
        singleCharKeyValue <<= i; //bitshift left https://www.arduino.cc/reference/en/language/structure/bitwise-operators/bitshiftleft/
        fullCharKeyValue = fullCharKeyValue | singleCharKeyValue; //Bitwise or https://www.arduino.cc/reference/en/language/structure/bitwise-operators/bitwiseor/
        delay(bouncetime);
        //if (DEBUG)Serial.println(fullCharKeyValue, BIN);
      }
    }
    if (!singleCharKeyValue && fullCharKeyValue) //only when X goes back to 0, return the last known values of a, but untill then keep updating a
    {
      delay(3* bouncetime);
      return fullCharKeyValue;
    }
    if (!fullCharKeyValue) //if none of the character buttons were pressed, check for function keys
      for (int i=6; i<15; i++)
      {
        if (digitalRead(pinMap[i]) == LOW)
        {
          functionKeyValue = B10000000;
          functionKeyValue += i;
          return functionKeyValue;
        }
      }
  }
}

char convert(byte keys) {
  for (int i = 0; i <= 56; i += 2) {
    if (keyMap[i] == keys)
      return keyMap[i - 1];
  }
  return 0;
}


/*
Function that reads the byte  value and returns a charector or function to perform
input: byte value of charecr keys or functions
output: char
*/
char processKeys(byte keyValue)
  {
    Serial.println(keyValue,BIN);
    char c = convert(keyValue);
    if (keyValue < B10000000) //Not a fucntion key press
    {
      if (c != '#')  //Not a number
        //return c;
         bleKeyboard.write(c);
      else
      {  label:
         keyValue= readKeys();
         if (convert(keyValue) == '#' or keyValue== 0)
          goto label;
        //keys = readKeys(pinMap[], bouncetime);
       // c = convert(keys) - 16;//ascii conversion from A to 1, B to 2 etc
         c = (convert(keyValue) - 48);//ascii conversion from A to 1, B to 2 etc
         Serial.println(c);
        if (c == 58) c = '0'; //0 after 9 not before 1 in braille alphabet
        //return c;
        bleKeyboard.write(c);
      }
    }
    else
    {
      switch (keyValue)
      {
        case B10000111:
        bleKeyboard.write(KEY_BACKSPACE);
        delay(100);
        break;
        case B10000110:
        bleKeyboard.write(' ');
        delay(100);
        break;
        case B10001000:
        bleKeyboard.write(KEY_ESC);
        delay(100);
        break;
        case B10001001:
        bleKeyboard.write(KEY_RETURN);
        delay(100);
        break;
        case B10001100:
        bleKeyboard.write(KEY_UP_ARROW);
        delay(100);
        break;
        case B10001010:
        bleKeyboard.write(KEY_DOWN_ARROW);
        delay(100);
        break;
        case B10001101:
        bleKeyboard.write(KEY_LEFT_ARROW);
        delay(100);
        break;
        case B10001011:
        bleKeyboard.write(KEY_RIGHT_ARROW);
        delay(100);
        break;
        case B10001110:
        bleKeyboard.write(KEY_TAB);
        delay(100);
        break;
      }
    }
  }


  void setup(){
  for (int i = 0; i< arraySize; i++)
  {
    pinMode(pinMap[i],INPUT_PULLUP);
  }
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleKeyboard.begin();
  }

  void loop(){
    if(bleKeyboard.isConnected()) {
      processKeys(readKeys());
//      ch = processKeys(readKeys());
//      if (ch)
//      {
//       bleKeyboard.write(ch);
//       ch = 0;
//      }
        delay(100);
        bleKeyboard.releaseAll();
      }
   
  }
