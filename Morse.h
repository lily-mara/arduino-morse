#ifndef Morse_h

#define Morse_h
#define LED_PIN 9
#define TIME_UNIT 100

class Morse { 
	public:	
		Morse(int pin);
		Morse(int pin, int timeUnit);
		void dot();
		void dash();
		void blinkString(String inString);
	private:	
		int _pin;
		int _timeUnit
};

#endif
