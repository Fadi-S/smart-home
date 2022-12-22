#include <Arduino.h>
#include "Water.h"


Water::Water(int analogInPin, int powerPin) {
  _analogInPin = analogInPin; 
  _powerPin = powerPin; 
}

void Water::setup() {
  pinMode(_analogInPin, INPUT);
  pinMode(_powerPin, OUTPUT);
}


int Water::get() {
  digitalWrite(_powerPin, HIGH);
  delay(10);
  int water = analogRead(_analogInPin);
  digitalWrite(_powerPin, LOW);

  return water;
}