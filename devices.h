#ifndef DEVICES_H
#define DEVICES_H

#include "foodGate.h"

#define FOOD_GATE_PIN 2

FoodGate foodGate = FoodGate(FOOD_GATE_PIN);

#endif // DEVICES_H