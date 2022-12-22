#ifndef water_h
#define water_h
#include <Arduino.h>

class Water { 
   public:
    Water(int analogInPin, int powerPin);
    int get();
    void setup();
   
   private:
    int _analogInPin;
    int _powerPin;

   
};

#endif