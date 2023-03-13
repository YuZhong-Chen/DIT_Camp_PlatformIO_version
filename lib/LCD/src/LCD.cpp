#include "LCD.h"

namespace LCD {

LiquidCrystal_PCF8574 lcd(0x27);

void Init() {
    lcd.begin(16, 2);  // initialize the lcd
    lcd.setBacklight(255);
    lcd.home();
    lcd.clear();
    lcd.setCursor(0, 0);
}

void print(String str) {
    lcd.setBacklight(255);
    lcd.home();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(str.c_str());
    lcd.setCursor(0, 1);
}

void print(double d) {
    lcd.setBacklight(255);
    lcd.home();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(d);
    lcd.setCursor(0, 1);
}

void print(int i) {
    lcd.setBacklight(255);
    lcd.home();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(i);
    lcd.setCursor(0, 1);
}

void print(char c) {
    lcd.setBacklight(255);
    lcd.home();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(c);
    lcd.setCursor(0, 1);
}

void println(String str) {
    print(str);
}

void println(double d) {
    print(d);
}

void println(int i) {
    print(i);
}

void println(char c) {
    print(c);
}

}  // namespace LCD
