#ifndef Door_h
#define Door_h
#include <Servo.h>
#include <Arduino.h>
class Door {
public:
  Door(int closeAngle,int openAngle,int pin);
  void setup();
  void open();
  void close();
private:
  int _closeAngle;
  int _openAngle;
  int _pos;
  int _pin;
};

#endif