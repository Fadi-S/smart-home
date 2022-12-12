#ifndef Temperature_h
#define Temperature_h

#include <Arduino.h>

class Temperature {

  public:
    Temperature(int _pin);

    void setup();
    String get();

  private:
    int _pin;
};

#endif