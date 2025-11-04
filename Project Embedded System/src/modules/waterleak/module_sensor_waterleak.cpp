#include <Arduino.h>
#include "module_sensor_waterleak.h"
#include "config/config.h"

#if USE_SENSOR_WATERLEAK
static int waterPin = SENSOR_WATERLEAK_PIN;
#endif

void initSensorWaterLeak(int pin) {
#if USE_SENSOR_WATERLEAK
  waterPin = pin;
  pinMode(waterPin, INPUT);
#endif
}

void readSensorWaterLeak() {
#if USE_SENSOR_WATERLEAK
  int value = analogRead(waterPin);
  Serial.print("Water Leak -> ");
  Serial.println(value);
#endif
}

int getWaterLeakLevel() {
#if USE_SENSOR_WATERLEAK
  return analogRead(waterPin);
#else
  return -1;
#endif
}
