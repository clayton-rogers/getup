/*



*/

const int PULSE_PIN = 3;

void setup() {
	Serial.begin(115200);

	Serial.print("Hello world\n");

	pinMode(PULSE_PIN, INPUT);
}

void loop() {
	while (LOW == digitalRead(PULSE_PIN)) {};
	const unsigned long start_time = micros();
	delay(500); // delay at least half a second to clear the pulse
	
	while (LOW == digitalRead(PULSE_PIN)) {};
	const unsigned long end_time = micros();
	Serial.println(end_time - start_time);
	delay(500); // again delay at least half a second to clear the pulse
}
