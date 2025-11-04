#include "module_buzzer.h"

static uint8_t buzzerPin;

void initBuzzer(uint8_t pin) {
  buzzerPin = pin;
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW);
}

void buzzerOn() {
  digitalWrite(buzzerPin, HIGH);
}

void buzzerOff() {
  digitalWrite(buzzerPin, LOW);
}
