/*

*/


enum class CPU_SPEED {
  TWO_FIVE_H_kHz,
  FIVE_H_kHz,
  ONE_MHz,
  TWO_MHz,
  FOUR_MHz,
  EIGHT_MHz,
};

void set_cpu_speed(CPU_SPEED speed){
  // NOTE: assumes clock is running at internal 8Mhz
  #if !(F_CPU == 8000000L)
  #error "This code only works on 8MHz processor"
  #endif

  
  byte new_clkpr = 0x00;
  switch (speed) {
    case CPU_SPEED::TWO_FIVE_H_kHz:
      new_clkpr = 0x05;
      break;
    case CPU_SPEED::FIVE_H_kHz:
      new_clkpr = 0x04;
      break;
    case CPU_SPEED::ONE_MHz:
      new_clkpr = 0x03;
      break;
    case CPU_SPEED::TWO_MHz:
      new_clkpr = 0x02;
      break;
    case CPU_SPEED::FOUR_MHz:
      new_clkpr = 0x01;
      break;
    case CPU_SPEED::EIGHT_MHz:
      new_clkpr = 0x00;
      break;
  }
  
  noInterrupts();
  CLKPR = 0x80; // Set clock prescale enable bit
  CLKPR = new_clkpr; // Set the new clock divider
  interrupts();
}

void setAllPullup() {
  for (int pin_id = 0; pin_id <= 20; ++pin_id) {
    pinMode(pin_id, INPUT_PULLUP);
  }
}



// the setup function runs once when you press reset or power the board
void setup() {
  setAllPullup();
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  
  set_cpu_speed(CPU_SPEED::ONE_MHz);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(20);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(2000);                       // wait for a second

  
}
