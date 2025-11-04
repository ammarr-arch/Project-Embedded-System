#pragma once
#include "config/config.h"

// Sensors
#if USE_SENSOR_DHT
  #include "modules/sensor_DHT/module_sensor_DHT.h"
#endif
#if USE_SENSOR_LDR
  #include "modules/sensor_LDR/module_sensor_LDR.h"
#endif

// IO
#if USE_SERIAL
  #include "modules/serial/module_serial.h"
  #include "modules/dashboard/module_dashboard.h"
#endif

// ===== Modul WiFi + Data =====
#if USE_WIFI
  #include "modules/Wifi/module_wifi.h"
  #include "modules/data/module_data.h"
  #include "modules/dashboard/module_dashboard_web.h"
#endif

