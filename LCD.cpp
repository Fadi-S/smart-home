#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "LCD.h"

LiquidCrystal_I2C lcd(0x27, 16, 2);


LCD::LCD(int pin) {}

void LCD::setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();
}

void LCD::setText1(String text) {
  _text1 = text;

  lcd.clear();

  lcd.setCursor(2,0);
  lcd.print(_text1);
  
  lcd.setCursor(2,1);
  lcd.print(_text2);
}

void LCD::setText2(String text) {
  _text2 = text;

  lcd.clear();

  lcd.setCursor(2,0);
  lcd.print(_text1);
  
  lcd.setCursor(2,1);
  lcd.print(_text2);
}