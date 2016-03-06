#include <DigitalPin.h>


DigitalPin Relay1(10); // Instantiates a DigitalPin object called "Relay1" that uses pin10
DigitalPin Relay2(11);

void setup() {
  Relay1.begin();
  Relay2.begin();
}

void loop() {
  Relay1.on();
  delay(1000);
  Relay1.off();
  delay(1000);
  Relay2.on();
  delay(1000);
  Relay2.off();
  delay(1000);
}

