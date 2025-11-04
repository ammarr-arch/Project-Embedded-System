#pragma once
#include "config/config.h"

// Sensors
#if USE_SENSOR_PZEM
  #include "modules/sensor_PZEM/module_sensor_PZEM.h"
#endif
#if USE_SENSOR_RFID
  #include "modules/rfid/modules_sensor_RFID.h"
#endif
#if USE_LED
  #include "modules/led/modules_LED.h"
#endif
#if USE_SD
  #include "modules/sd/modules_SD.h"
#endif
#if USE_LCD
  #include "modules/lcd/modules_LCD.h"
#endif
#if USE_SENSOR_DHT
  #include "modules/sensor_DHT/module_sensor_DHT.h"
#endif
#if USE_SENSOR_LDR
  #include "modules/sensor_LDR/module_sensor_LDR.h"
#endif
#if USE_SENSOR_LM35
  #include "modules/sensor_LM35/module_sensor_LM35.h"
#endif
#if USE_SENSOR_WATERLEAK
  #include "modules/waterleak/module_sensor_waterleak.h"
#endif
#if USE_RELAY
  #include "modules/relay/module_relay.h"
#endif
// IO
#if USE_SERIAL
  #include "modules/serial/module_serial.h"
  #include "modules/dashboard/module_dashboard.h"
#endif
#if USE_BUZZER
  #include "modules/buzzer/module_buzzer.h"
#endif
// ===== Modul WiFi + Data =====
#if USE_WIFI
  #include "modules/Wifi/module_wifi.h"
  #include "modules/data/module_data.h"
  #include "modules/dashboard/module_dashboard_web.h"
#endif

