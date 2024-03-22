#include "foodGate.h"

FoodGate::FoodGate(const uint8_t fgPin) : state(false) {
    servo.attach(fgPin);
    close();
}

void FoodGate::open() {
    servo.write(180);
    state = true;
}

void FoodGate::close() {
    servo.write(0);
    state = false;
}

bool FoodGate::isOpen() {
    return state;
}