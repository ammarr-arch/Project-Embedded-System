#ifndef MODULE_SENSOR_LM35_H
#define MODULE_SENSOR_LM35_H

#include <Arduino.h>

// Inisialisasi sensor LM35 pada pin tertentu
void initSensorLM35(uint8_t pin);

// Membaca suhu dari LM35 dan mengembalikan nilai suhu dalam °C
void readSensorLM35();        // fungsi ini membaca & menyimpan suhu
float getTemperatureLM35();   // fungsi ini mengembalikan suhu terakhir yang dibaca

#endif // MODULE_SENSOR_LM35_H
