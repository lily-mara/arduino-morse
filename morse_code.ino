#include <Morse.h>
Morse morse(8, 100);

void setup() {
  Serial.begin(9600);
}

/*
 * main loop, gets Strings from serial using readString(), and calls
 * blinkString() on the String if it is non-empty.
 */

void loop() {
  String inString = readString();
  if (! inString.equals("")) {
    morse.blinkString(inString);
    Serial.println(0);
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
