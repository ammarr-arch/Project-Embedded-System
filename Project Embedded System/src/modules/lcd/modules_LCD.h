#pragma once
#include "config/config_requirement.h"
#include <LiquidCrystal_I2C.h>
#ifndef MODULES_LCD_H
#define MODULES_LCD_H
extern LiquidCrystal_I2C lcd;
#define LCD_ADDR 0x27   // Alamat I2C LCD, biasanya 0x27 atau 0x3F
#define LCD_COLS 16     // Jumlah kolom LCD
#define LCD_ROWS 2 
void setupLCD();
void updateLCD(float v,float i,float p,float e,float pf);
#endif