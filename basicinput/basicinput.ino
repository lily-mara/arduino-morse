const int switchPin = 7;
const int ledPin = 8;

void setup() {
  pinMode(switchPin, INPUT);      
  pinMode(ledPin, OUTPUT);      
  Serial.begin(9600);
}

void loop() {
  int read = digitalRead(switchPin);
  if (read == HIGH) {
    int start = millis();
  }
  else {
    digitalWrite(ledPin, LOW);
    /* Serial.println("OFF"); */
  }
  delay(10);
}