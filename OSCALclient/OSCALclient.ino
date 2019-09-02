/*
  NOTE:
    This sketch is running at the built-in 8 Mhz
	It is used to 
*/

const int PIN_UP = 9;
const int PIN_DOWN = 10;

// This function copied from the board detector elsewhere in this repo
void showHex (const byte b, const boolean newline = false) {
	// try to avoid using sprintf
	char buf [4] = { ((b >> 4) & 0x0F) | '0', (b & 0x0F) | '0', ' ' , 0 };
	if (buf [0] > '9')
		buf [0] += 7;
	if (buf [1] > '9')
		buf [1] += 7;
	Serial.print (buf);
	if (newline)
		Serial.println ();
}  // end of showHex

void pulseLED() {
	digitalWrite(LED_BUILTIN, HIGH);
	delay(1);
	digitalWrite(LED_BUILTIN, LOW);
}

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
	pinMode(PIN_UP, INPUT_PULLUP);
	pinMode(PIN_DOWN, INPUT_PULLUP);
	
	Serial.begin(57600);
	Serial.println("Hello world");
	
	showHex(OSCCAL, true);
}

void loop() {
	unsigned char cur_OSCCAL = OSCCAL;
	
	while (true) {
		delay(1500); // Wait a bit for server to start
		pulseLED();
		delay(10000);
		pulseLED();
		
		if (LOW == digitalRead(PIN_UP)) {
			cur_OSCCAL++;
			OSCCAL = cur_OSCCAL;
		}
		
		if (LOW == digitalRead(PIN_DOWN)) {
			cur_OSCCAL--;
			OSCCAL = cur_OSCCAL;
		}
		
		showHex(cur_OSCCAL, true);
	}
}
