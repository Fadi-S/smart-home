#ifndef Buzzer_h
#define Buzzer_h

#include <Arduino.h>

class Buzzer {

  public:
    Buzzer(int pin);

    void start();

    void startFor(int millis);

    void stop();

    void toggle(int millis, int times);

  private:
    int _pin;
};

#endif