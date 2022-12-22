#include <Arduino.h>
#include <DHT.h>
#include "Temperature.h"

#define DHTPIN 12
#define DHTTYPE DHT22   // DHT 22  (AM2302)
DHT dht(DHTPIN, DHTTYPE); 

Temperature::Temperature(int pin) {

}

void Temperature::setup() {
  dht.begin();
}

String Temperature::get() {
  float temp = dht.readTemperature();

  return String(temp, 1);
}