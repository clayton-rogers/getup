/*
  NOTE:
    This sketch is running at the built-in 8 Mhz
*/

void setup() {
	pinMode(LED_BUILTIN, OUTPUT);
}

void pulseLED() {
	digitalWrite(LED_BUILTIN, HIGH);
	delay(1);
	digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
	while (true) {
		delay(10000);
		pulseLED();
	}
}
