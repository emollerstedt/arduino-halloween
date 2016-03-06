#include "DigitalPin.h"

DigitalPin::DigitalPin(int pin)
{
  _pin = pin;
}

void DigitalPin::begin() //This initializes the pin
{
  pinMode(_pin, OUTPUT);
}

void DigitalPin::on()
{
  digitalWrite(_pin, HIGH);
  _status=1;
}

void DigitalPin::off()
{
  digitalWrite(_pin, LOW);
  _status=0;
}

bool DigitalPin::status()
{
  return _status;
}
