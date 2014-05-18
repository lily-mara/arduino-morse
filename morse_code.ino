#include "Morse.h"

void setup() {
  pinMode(LED_PIN, OUTPUT);      
  Serial.begin(9600);
}

/*
 * main loop, gets Strings from serial using readString(), and calls
 * blinkString() on the String if it is non-empty.
 */

void loop() {
  String inString = readString();
  if (! inString.equals("")) {
    blinkString(inString);
    Serial.write(1);
  }
}

/*
 * Reads char sequence from serial and returns a String
 */
String readString() {
  String content = "";
  char character;

  while(Serial.available()) {
      character = Serial.read();
      content.concat(character);
      delay(10);
  }

  return content;
}
