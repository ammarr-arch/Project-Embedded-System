#include <Arduino.h>
#include "module_dashboard.h"
#include "config/config.h"

#if USE_SENSOR_DHT
  #include "modules/sensor_DHT/module_sensor_DHT.h"
#endif

#if USE_SENSOR_LDR
  #include "modules/sensor_LDR/module_sensor_LDR.h"
#endif

void showDashboard() {
  #if USE_SERIAL
    Serial.println(F("===== Dashboard ====="));

    // --- DHT Sensor (Temp & Humidity) ---
    #if USE_SENSOR_DHT
      Serial.print(F("Temp: "));
      Serial.print(getTemperature());
      Serial.print(F(" °C, Hum: "));
      Serial.print(getHumidity());
      Serial.println(F(" %"));
    #else
      Serial.println(F("Temp: null, Hum: null"));
    #endif

    // --- LDR Sensor (Light) ---
    #if USE_SENSOR_LDR
      Serial.print(F("Light: "));
      Serial.println(getLightLevel());
    #else
      Serial.println(F("Light: null"));
    #endif

    Serial.println(F("======================"));
  #endif
}