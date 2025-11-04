#include <Arduino.h>
#include "module_relay.h"
#include "config/config.h"

static int relayPin = -1;

void initRelay(int pin) {
    relayPin = pin;
    pinMode(relayPin, OUTPUT);
    digitalWrite(relayPin, LOW); // Default mati
}

void relayOn() {
    digitalWrite(relayPin, HIGH);
}

void relayOff() {
    digitalWrite(relayPin, LOW);
}
