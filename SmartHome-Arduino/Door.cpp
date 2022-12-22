#include <Arduino.h>
#include <Servo.h>
#include "Door.h"

Servo servo;

Door::Door(int closeAngle, int openAngle, int pin){
  _closeAngle = closeAngle;
  _openAngle =openAngle;
  _pin=pin;
}

void Door::setup() {
  servo.attach(_pin);
}


void Door::open(){
  servo.write(_openAngle);
}
void Door::close(){
   servo.write(_closeAngle);
}
