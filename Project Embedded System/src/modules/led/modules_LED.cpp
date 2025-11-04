#include <Arduino.h>
#include "modules_LED.h"

void initLed() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void setLed(bool state) {
  digitalWrite(LED_PIN, state ? HIGH : LOW);
}
void ledOn() {
    digitalWrite(LED_PIN, HIGH);
}

void ledOff() {
    digitalWrite(LED_PIN, LOW);
}