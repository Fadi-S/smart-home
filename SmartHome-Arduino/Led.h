#ifndef Led_h
#define Led_h

#include <Arduino.h>

class Led {

  public:
    Led(int pin);

    void on();
    void off();
    void toggle();

    bool isOn();

  private:
    int _pin;
    bool _isOn;
};

#endif