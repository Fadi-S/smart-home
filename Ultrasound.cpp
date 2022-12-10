#include <Arduino.h>
#include "Ultrasound.h"


Ultrasound::Ultrasound(int echoPin, int trigPin) {
  _echoPin = echoPin;
  _trigPin = trigPin;

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

int Ultrasound::getDistance() {
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  _duration = pulseIn(_echoPin, HIGH);

  // Calculating the distance
  return _duration * 0.034 / 2;
}