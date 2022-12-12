#ifndef LCD_h
#define LCD_h

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class LCD {

  public:
    LCD(int _pin);

    void setup();
    void setText1(String text);
    void setText2(String text);

  private:
    int _SCLPin;
    int _SDAPin;
    String _text1;
    String _text2;
};

#endif