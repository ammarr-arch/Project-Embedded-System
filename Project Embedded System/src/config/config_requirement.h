#pragma once
#include <stdint.h>
#include <Arduino.h>

// ========================
// Pilih salah satu project dengan cara uncomment
// ========================
// #define PROJECT_STUDI1
// #define PROJECT_STUDI2
// #define PROJECT_STUDI3
#define PROJECT_STUDI4
// ========================
// Pilih tipe DHT sensor: DHT11 atau DHT22 dengan cara uncomment
// ========================
#define DHT_TYPE DHT22
// #define DHT_TYPE DHT11

#ifndef DHT_TYPE
  #error "Pilih tipe DHT sensor: DHT11 atau DHT22"
#endif

// ========================
// Automatic Config Mapping
// ========================
#if defined(PROJECT_STUDI1)        // UNO: DHT + LDR
  #define TARGET_UNO
  #define USE_SENSOR_DHT    1
  #define USE_SENSOR_LDR    1
  #define USE_WIFI          0
  #define USE_SERIAL        1
  #define SENSOR_DHT_PIN    2     // Digital pin 2 pada Arduino UNO
  #define SENSOR_LDR_PIN    A0    // Analog pin A0-A5 pada Arduino UNO
  #define SERIAL_BAUD       9600

#elif defined(PROJECT_STUDI2)      // ESP32: DHT + WiFi
  #define TARGET_ESP32
  #define USE_SENSOR_DHT    1
  #define USE_SENSOR_LDR    0
  #define USE_WIFI          1
  #define USE_SERIAL        1
  #define SENSOR_DHT_PIN    4
  #define SERIAL_BAUD       115200

#elif defined(PROJECT_STUDI3)      // ESP32: DHT + LDR + WiFi
  #define TARGET_ESP32
  #define USE_SENSOR_DHT    1
  #define USE_SENSOR_LDR    1
  #define USE_WIFI          1
  #define USE_SERIAL        1
  #define SENSOR_DHT_PIN    4
  #define SENSOR_LDR_PIN    34
  #define SERIAL_BAUD       115200

#elif defined(PROJECT_STUDI4)      // ESP32: LDR + WiFi
  #define TARGET_ESP32
  #define USE_SENSOR_DHT    0
  #define USE_SENSOR_LDR    1
  #define USE_WIFI          1
  #define USE_SERIAL        1

  #if USE_SENSOR_LDR
    #define SENSOR_LDR_PIN  34
  #endif

  #define SERIAL_BAUD       115200

#else
  #error "Pilih salah satu PROJECT_STUDI* di config_requirement.h"
#endif

// ========================
// Extra Validations
// ========================
#if USE_SENSOR_DHT && !defined(SENSOR_DHT_PIN)
  #error "SENSOR_DHT_PIN harus didefinisikan jika USE_SENSOR_DHT=1"
#endif

#if USE_SENSOR_LDR && !defined(SENSOR_LDR_PIN)
  #error "SENSOR_LDR_PIN harus didefinisikan jika USE_SENSOR_LDR=1"
#endif

#if defined(TARGET_UNO) && USE_WIFI
  #error "WiFi tidak tersedia di UNO. Gunakan ESP32"
#endif

#if USE_WIFI
  #define WIFI_SSID "admin"
  #define WIFI_PASS "12345"
#endif

