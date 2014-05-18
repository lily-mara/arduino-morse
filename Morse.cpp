#include <Morse>	

/*
 * produces a single "dot"/"dit" (shorter symbol) on the led
 */
Morse::void dot() {
  digitalWrite(LED_PIN, HIGH);
  delay(1 * TIME_UNIT);
  digitalWrite(LED_PIN, LOW);
  delay(1 * TIME_UNIT);
}

/*
 * produces a single "dash" (longer symbol) on the led
 */
Morse::void dash() {
  digitalWrite(LED_PIN, HIGH);
  delay(3 * TIME_UNIT);
  digitalWrite(LED_PIN, LOW);
  delay(1 * TIME_UNIT);
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
    delay(3 * TIME_UNIT);
  }
  delay(7 * TIME_UNIT);
}
