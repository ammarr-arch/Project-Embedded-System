#pragma once
#include <stdint.h>
#include <Arduino.h>

// ========================
// Pilih salah satu project dengan cara uncomment
// ========================
//#define PROJECT_STUDI1 //ESP32 FARIZ
//#define PROJECT_STUDI2 //UNO FARIZ
//#define PROJECT_STUDI3 //ESP32 AMMAR
//#define PROJECT_STUDI4  //UNO AMMAR
//#define PROJECT_STUDI5 //ESP32 SULTON
//#define PROJECT_STUDI6 // UNO SULTON
//#define PROJECT_STUDI7 //UNO FIRDA
//#define PROJECT_STUDI8 //ESP32 FIRDA
#define PROJECT_STUDI9 // ESP32 GRITA
//#define PROJECT_STUDI10 // UNO GRITA
//#define PROJECT_STUDI11 // ESP32 FAUZAN
//#define PROJECT_STUDI12 // UNO FAUZAN
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
  #define TARGET_ESP32
  #define USE_SENSOR_DHT    1
  #define USE_SENSOR_LDR    0
  #define USE_SENSOR_LM35   0
  #define USE_SENSOR_PZEM   0
  #define USE_WIFI          0
  #define USE_SERIAL        1
  #define USE_BUZZER        1
  #define USE_LED           1
  #define SENSOR_LM35_PIN   34
  #define SENSOR_DHT_PIN    35
  #define BUZZER_PIN        24
  #define PZEM_RX_PIN       26
  #define PZEM_TX_PIN       27
  #define LCD_ADDR          0x27
  #define LCD_COLS          16
  #define LCD_ROWS          2
  #define SERIAL_BAUD       115200

#elif defined(PROJECT_STUDI2)      // ESP32: DHT + WiFi
 #define TARGET_UNO
  #define USE_SENSOR_DHT    1
  #define USE_SENSOR_LDR    0
  #define USE_SENSOR_LM35   0
  #define USE_SENSOR_PZEM   0
  #define USE_WIFI          0
  #define USE_SERIAL        1
  #define USE_BUZZER        1
  #define USE_LED           1
  #define SENSOR_DHT_PIN    A0
  #define SENSOR_LM35_PIN   34
  #define BUZZER_PIN        24
  #define PZEM_RX_PIN       26
  #define PZEM_TX_PIN       27
  #define LCD_ADDR          0x27
  #define LCD_COLS          16
  #define LCD_ROWS          2
  #define SERIAL_BAUD       115200

#elif defined(PROJECT_STUDI3)
  #define TARGET_ESP32
  #define USE_SENSOR_DHT    0
  #define USE_SENSOR_LDR    0
  #define USE_SENSOR_LM35   1
  #define USE_SENSOR_PZEM   0
  #define USE_WIFI          0
  #define USE_SERIAL        1
  #define USE_BUZZER        1
  #define USE_LCD           0
  #define USE_LED           1
  #define SENSOR_LM35_PIN   34
  #define BUZZER_PIN        24
  #define PZEM_RX_PIN       26
  #define PZEM_TX_PIN       27
  #define LCD_ADDR          0x27
  #define LCD_COLS          16
  #define LCD_ROWS          2
  #define SERIAL_BAUD       115200

#elif defined(PROJECT_STUDI4)
  #define TARGET_UNO
  #define USE_SENSOR_DHT    0
  #define USE_SENSOR_LDR    0
  #define USE_SENSOR_LM35   1
  #define USE_SENSOR_PZEM   0
  #define USE_WIFI          0
  #define USE_SERIAL        1
  #define USE_BUZZER        1
  #define SENSOR_LM35_PIN   A0
  #define BUZZER_PIN        7
  #define USE_SENSOR_PZEM   0
  #define PZEM_RX_PIN       26
  #define PZEM_TX_PIN       27
  #define LCD_ADDR          0x27
  #define LCD_COLS          16
  #define LCD_ROWS          2
  #define SERIAL_BAUD       115200

#elif defined(PROJECT_STUDI5)
  #define TARGET_ESP32
  #define USE_SENSOR_DHT    0
  #define USE_SENSOR_LDR    1
  #define USE_SENSOR_LM35   0
  #define USE_SENSOR_PZEM   0
  #define USE_WIFI          0
  #define USE_SERIAL        1
  #define USE_BUZZER        0
  #define USE_RELAY         1
  #define USE_LED           1
  #define USE_LED           1
  #define SENSOR_LDR_PIN    34
  #define RELAY_PIN         24
  #define USE_SENSOR_PZEM   0
  #define PZEM_RX_PIN       26
  #define PZEM_TX_PIN       27
  #define LCD_ADDR          0x27
  #define LCD_COLS          16
  #define LCD_ROWS          2
  #define SERIAL_BAUD       115200

#elif defined(PROJECT_STUDI6)
  #define TARGET_UNO
  #define USE_SENSOR_DHT    0
  #define USE_SENSOR_LDR    1
  #define USE_SENSOR_LM35   0
  #define USE_SENSOR_PZEM   0
  #define USE_WIFI          0
  #define USE_SERIAL        1
  #define USE_BUZZER        0
  #define USE_RELAY         1
  #define USE_LED           1
  #define SENSOR_LDR_PIN    A0
  #define RELAY_PIN         24
  #define USE_SENSOR_PZEM   0
  #define PZEM_RX_PIN       26
  #define PZEM_TX_PIN       27
  #define LCD_ADDR          0x27
  #define LCD_COLS          16
  #define LCD_ROWS          2
  #define SERIAL_BAUD       115200

#elif defined(PROJECT_STUDI7)      // ESP32: RFID + LED
  #define TARGET_UNO
  #define USE_SENSOR_DHT    0
  #define USE_SENSOR_LDR    0
  #define USE_SENSOR_PZEM   0
  #define USE_WIFI          0
  #define USE_SERIAL        1
  #define USE_SENSOR_RFID   1
  #define USE_LED           1
  #define RFID_SS_PIN       5     // SDA
  #define RFID_RST_PIN      22
  #define LED_PIN           2
  #define PZEM_RX_PIN       26
  #define PZEM_TX_PIN       27
  #define LCD_ADDR          0x27
  #define LCD_COLS          16
  #define LCD_ROWS          2     
  #define SERIAL_BAUD       115200

#elif defined(PROJECT_STUDI8)      // ESP32: RFID + LED
  #define TARGET_ESP32
  #define USE_SENSOR_DHT    0
  #define USE_SENSOR_LDR    0
  #define USE_SENSOR_PZEM   0
  #define USE_WIFI          0
  #define USE_SERIAL        1
  #define USE_SENSOR_RFID   1
  #define USE_LED           1
  #define RFID_SS_PIN       5     // SDA
  #define RFID_RST_PIN      22
  #define LED_PIN           2
  #define PZEM_RX_PIN       26
  #define PZEM_TX_PIN       27
  #define LCD_ADDR          0x27
  #define LCD_COLS          16
  #define LCD_ROWS          2     
  #define SERIAL_BAUD       115200

#elif defined(PROJECT_STUDI9)
  #define TARGET_ESP32
  #define USE_SENSOR_WATERLEAK 1
  #define USE_SENSOR_DHT    0
  #define USE_SENSOR_LDR    0
  #define USE_SENSOR_LM35   0
  #define USE_SENSOR_PZEM   0
  #define USE_WIFI          0
  #define USE_BUZZER        1
  #define USE_SERIAL        1
  #define USE_RELAY         1 
  #define USE_BAUD          115200
  #define BUZZER_PIN        35
  #define SENSOR_WATERLEAK_PIN 35
  #define RELAY_PIN         25
  #define PZEM_RX_PIN       26
  #define PZEM_TX_PIN       27
  #define LCD_ADDR          0x27
  #define LCD_COLS          16
  #define LCD_ROWS          2

  #elif defined(PROJECT_STUDI10)
  #define TARGET_UNO
  #define USE_SENSOR_WATERLEAK 1
  #define USE_SENSOR_DHT    0
  #define USE_SENSOR_LDR    0
  #define USE_SENSOR_PZEM   0
  #define USE_SENSOR_LM35   0
  #define USE_BUZZER        1
  #define USE_WIFI          0
  #define USE_SERIAL        1
  #define USE_RELAY         1 
  #define USE_BAUD          115200
  #define BUZZER_PIN        6
  #define SENSOR_WATERLEAK_PIN 35
  #define RELAY_PIN         25
  #define PZEM_RX_PIN       26
  #define PZEM_TX_PIN       27
  #define LCD_ADDR          0x27
  #define LCD_COLS          16
  #define LCD_ROWS          2

#elif defined(PROJECT_STUDI11)     // ESP32: Smart Energy Monitoring (Cloud + SD + LCD)
  #define TARGET_ESP32
  #define USE_SENSOR_PZEM   1
  #define USE_LCD           1
  #define USE_WIFI          1
  #define USE_SERIAL        1
  #define USE_BUZZER        1
  #define PZEM_RX_PIN       26
  #define PZEM_TX_PIN       27
  #define LCD_ADDR          0x27
  #define LCD_COLS          16
  #define BUZZER_PIN        35
  #define LCD_ROWS          2
  #define SD_CS_PIN         5
  #define SERIAL_BAUD       115200
  #define CLOUD_API_KEY     "YOUR_API_KEY"
  #define CLOUD_SERVER      "api.thingspeak.com"

#elif defined(PROJECT_STUDI12)     // Arduino Nano: Smart Energy Monitoring (SD + LCD)
  #define TARGET_UNO
  #define USE_SENSOR_PZEM   1
  #define USE_LCD           1
  #define USE_BUZZER        1
  #define USE_WIFI          0
  #define USE_SERIAL        1
  #define PZEM_RX_PIN       10
  #define PZEM_TX_PIN       11
  #define LCD_ADDR          0x27
  #define LCD_COLS          16
  #define LCD_ROWS          2
  #define BUZZER_PIN        6
  #define SD_CS_PIN         4
  #define SERIAL_BAUD       115200

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

