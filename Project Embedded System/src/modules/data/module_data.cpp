#include <Arduino.h>
#include <ArduinoJson.h>
#include "module_data.h"
#include "config/config.h"

// pastikan include sensor yang aktif
#if USE_SENSOR_DHT
  #include "modules/sensor_DHT/module_sensor_DHT.h"
#endif
#if USE_SENSOR_LDR
  #include "modules/sensor_LDR/module_sensor_LDR.h"
#endif

String buildSensorJSON() {
   JsonDocument doc;   // ✅ ganti dari StaticJsonDocument (deprecated)

  #if USE_SENSOR_DHT
    doc["temperature"] = getTemperature();
    doc["humidity"]    = getHumidity();
  #endif

  #if USE_SENSOR_LDR
    doc["light"] = getLightLevel();
  #endif

  String output;
  serializeJson(doc, output);
  return output;
}
