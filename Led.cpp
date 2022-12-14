#include <Arduino.h>
#include "Led.h"


Led::Led(int pin) {
  _pin = pin;
}

void Led::on() {
  _isOn = true;
}

void Led::off() {
  _isOn = false;
}

void Led::toggle() {
  _isOn = !_isOn;
}

bool Led::isOn() {
  return _isOn;
}