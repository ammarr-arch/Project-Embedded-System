#pragma once
#include "config/config_requirement.h"

void setupSensor();
void readSensor(float &v, float &i, float &p, float &e, float &pf);