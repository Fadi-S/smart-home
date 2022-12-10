#ifndef Ultrasound_h
#define Ultrasound_h

#include <Arduino.h>

class Ultrasound {

  public:
    Ultrasound(int echoPin, int trigPin);

    int getDistance();

  private:
    int _echoPin;
    int _trigPin;
    long _duration;
};

#endif