#include <Arduino.h>
#include "submain.h"

void test_dht_sensor() {
#if USE_SENSOR_DHT
    initSensorDHT(SENSOR_DHT_PIN);
    delay(2000); // waktu stabilisasi
    readSensorDHT();
    float t = getTemperature();
    float h = getHumidity();
    TEST_ASSERT(t > -40 && t < 80);   // range suhu normal
    TEST_ASSERT(h >= 0 && h <= 100);  // range kelembaban
#endif
}

void test_ldr_sensor() {
#if USE_SENSOR_LDR
    initSensorLDR(SENSOR_LDR_PIN);
    int val = getLightLevel();
    TEST_ASSERT(val >= 0 && val <= 1023);  // range ADC UNO
#endif
}

void setup() {
    UNITY_BEGIN();
    RUN_TEST(test_dht_sensor);
    RUN_TEST(test_ldr_sensor);
    UNITY_END();
}

void loop() {}
