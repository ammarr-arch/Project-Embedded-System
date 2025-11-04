#pragma once
#include "config_requirement.h"

#if defined(TARGET_ESP32)
  #define PZEM_RX_PIN      17
  #define PZEM_TX_PIN      16
  #define LCD_ADDR         0x27
  #define LCD_COLS         16
  #define LCD_ROWS         2
#elif defined(TARGET_UNO)

  #define PZEM_RX_PIN      3
  #define PZEM_TX_PIN      2
  #define LCD_ADDR         0x27
  #define LCD_COLS         16
  #define LCD_ROWS         2
#else
  #error "❌ Harap tentukan target board: #define TARGET_ESP32 atau #define TARGET_UNO"
#endif