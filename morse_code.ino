const int ledPin = 9;
const int timeUnit = 200;

int ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);      
  Serial.begin(9600);
}

void loop() {
  String inString = readString();
  if (! inString.equals("")) {
    blinkString(inString);
  }
}

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

void blinkSerialChar() {
  if (Serial.available() > 0) {
    char incomingChar = (char) Serial.read();
    
    blinkChar(incomingChar);
  }
}

void dot() {
  digitalWrite(ledPin, HIGH);
  delay(1 * timeUnit);
  digitalWrite(ledPin, LOW);
  delay(1 * timeUnit);
}

void dash() {
  digitalWrite(ledPin, HIGH);
  delay(3 * timeUnit);
  digitalWrite(ledPin, LOW);
  delay(1 * timeUnit);
}

void blinkChar(char toBlink) {
  char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
  char* morseArray[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".--", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "----.", "-----", "|"};
  int position = find(alphabet, toBlink);
  
  String morseLetter = morseArray[position];
  
  for (int i = 0; i < morseLetter.length(); i++) {
    char currentChar = morseLetter.charAt(i);
    if (currentChar == '.')
      dot();
    else if (currentChar == '-')
      dash();
  }
}

int find(char array[], char toFind) {
  for (int i = 0; i < 26; i++) {
    if (array[i] == toFind)
      return i;
  }
  return -1;
}

void blinkString(String toBlink) {
  for (int i = 0; i < toBlink.length(); i++) {
    blinkChar(toBlink.charAt(i));
    delay(3 * timeUnit);
  }
  delay(7 * timeUnit);
}