#include <Arduino.h>

void setup() {
  Serial.begin(9600);
  for (int i=2; i<=35;i++)
  {
    pinMode(i,INPUT_PULLUP);
  }

}

void loop() {
  for (int i=2; i<=35;i++)
  {
    if (digitalRead(i) == LOW)
    {Serial.print("Button Pressed: ");
    Serial.print(i);
    Serial.println();
}
  }
}