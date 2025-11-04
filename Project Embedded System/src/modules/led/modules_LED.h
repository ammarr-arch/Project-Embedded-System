#pragma once
#include <Arduino.h>

#define LED_PIN 2  // ubah sesuai pin yang kamu pakai

void initLed();
void setLed(bool state);
void ledOn();
void ledOff();