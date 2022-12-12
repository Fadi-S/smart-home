#include <Arduino.h>
#include "Temperature.h"

Temperature::Temperature(int pin) {}

void Temperature::setup() {

}

String Temperature::get() {
  return "25";
}