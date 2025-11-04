#include "module_sensor_LM35.h"
#include "config/config.h"
#include <Arduino.h>

#if USE_SENSOR_LM35

static float lastTempLM35 = NAN;

void initSensorLM35(uint8_t pin) {
  pinMode(pin, INPUT);
  #if USE_SERIAL
    Serial.println(F("LM35 sensor initialized"));
  #endif
}

void readSensorLM35() {
  int sensorValue = analogRead(SENSOR_LM35_PIN);
  float voltage = sensorValue * (3.3 / 4095.0);
  float temperature = voltage * 100.0; // 10mV per °C
  lastTempLM35 = temperature;

  #if USE_SERIAL
    Serial.print(F("LM35 -> Temp: "));
    Serial.print(temperature);
    Serial.println(F(" *C"));
  #endif
}

float getTemperatureLM35() {
  return lastTempLM35;
}

#else
void initSensorLM35(uint8_t pin) {}
void readSensorLM35() {}
float getTemperatureLM35() { return -1; }
#endif
