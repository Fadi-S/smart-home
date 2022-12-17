#include <Arduino.h>
#include "Led.h"


Led::Led(int pin) {
  _pin = pin;

  pinMode(pin, OUTPUT);
}

void Led::on() {
  digitalWrite(_pin, HIGH);
  _isOn = true;
}

void Led::off() {
  digitalWrite(_pin, LOW);
  _isOn = false;
}

void Led::toggle() {
  digitalWrite(_pin, !_isOn);
  _isOn = !_isOn;
}

bool Led::isOn() {
  return _isOn;
}