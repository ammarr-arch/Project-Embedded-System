#include "modules/lcd/modules_LCD.h"
#include "config/config_requirement.h"
#include <LiquidCrystal_I2C.h>
// Definisi satu-satunya objek LCD
LiquidCrystal_I2C lcd(LCD_ADDR, LCD_COLS, LCD_ROWS);

void setupLCD() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Smart Energy Mon");
}

void updateLCD(float v, float i, float p, float e, float pf) {
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("V:");
  lcd.print(v, 1);   // 1 angka di belakang koma
  lcd.print(" I:");
  lcd.print(i, 2);   // 2 angka di belakang koma

  lcd.setCursor(0, 1);
  lcd.print("P:");
  lcd.print(p, 0);   // tanpa desimal
  lcd.print("W E:");
  lcd.print(e, 2);   // 2 angka desimal
}
