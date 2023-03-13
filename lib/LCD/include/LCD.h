#ifndef _LCD_H_
#define _LCD_H_

#include <ArduinoSTL.h>
#include <LiquidCrystal_PCF8574.h>
#include <Wire.h>

namespace LCD {

// Address: 0x27
extern LiquidCrystal_PCF8574 lcd;

void Init();
void print(String str);
void print(double d);
void print(int i);
void print(char c);
void println(String str);
void println(double d);
void println(int i);
void println(char c);

}  // namespace LCD

#endif