#include <Arduino.h>
#include "Buzzer.h"


Buzzer::Buzzer(int pin) {
  _pin = pin;

  pinMode(pin, OUTPUT);
}

void Buzzer::start() {
  digitalWrite(_pin, HIGH);
}

void Buzzer::startFor(int millis) {
  digitalWrite(_pin, HIGH);
  delay(millis);
  digitalWrite(_pin, LOW);
}

void Buzzer::stop() {
  digitalWrite(_pin, LOW);
}

void Buzzer::toggle(int millis, int times) {
  for(int i=0; i<times; i++) {
    digitalWrite(_pin, HIGH);
    delay(millis);
    digitalWrite(_pin, LOW);
    delay(millis);
  }
}