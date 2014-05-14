const int ledPin = 9;
const int timeUnit = 100;

int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);      
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

/*
 * produces a single "dot"/"dit" (shorter symbol) on the led
 */
void dot() {
  digitalWrite(ledPin, HIGH);
  delay(1 * timeUnit);
  digitalWrite(ledPin, LOW);
  delay(1 * timeUnit);
}

/*
 * produces a single "dash" (longer symbol) on the led
 */
void dash() {
  digitalWrite(ledPin, HIGH);
  delay(3 * timeUnit);
  digitalWrite(ledPin, LOW);
  delay(1 * timeUnit);
}

/*
 * Blinks the given char
 *
 * param toBlink
 *   the char to blink
 */
void blinkChar(char toBlink) {
  char* morseArray[] = {".-", "-...", "-.-.", "-..", ".", "..-.",
			"--.", "....", "..", ".--", "-.-", ".-..",
			"--", "-.", "---", ".--.", "--.-", ".-.",
			"...", "-", "..-", "...-", ".--", "-..-",
			"-.--", "--..", ".----", "..---", "...--",
			"....-", ".....", "-....", "--...", "---..",
			"----.", "-----"};

  int position = lookupChar(toBlink);
  
  String morseLetter = morseArray[position];
  
  for (int i = 0; i < morseLetter.length(); i++) {
    char currentChar = morseLetter.charAt(i);
    if (currentChar == '.')
      dot();
    else if (currentChar == '-')
      dash();
  }
}

/*
 * Returns the position in the alphabet of the given char, if not
 * found, returns -1
 *
 * param toFind
 *   the char to find in the alphabet
 */
int lookupChar(char toFind) {
  char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
		     'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
		     'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4',
		     '5', '6', '7', '8', '9', '0'};

  for (int i = 0; i < 36; i++) {
    if (alphabet[i] == toFind)
      return i;
  }
  return -1;
}

/*
 * Blinks each character in the string using the correct morse code times
 *
 * param toBlink
 *   the String to blink
 */
void blinkString(String toBlink) {
  for (int i = 0; i < toBlink.length(); i++) {
    blinkChar(toBlink.charAt(i));
    delay(3 * timeUnit);
  }
  delay(7 * timeUnit);
}