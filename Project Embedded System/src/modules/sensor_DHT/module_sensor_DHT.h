// module_sensor DHT.h
#pragma once

void initSensorDHT(int pin);
void readSensorDHT();
float getTemperature();
float getHumidity();
