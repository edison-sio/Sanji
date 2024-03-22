#ifndef FOODGATE_H
#define FOODGATE_H

#include <Servo.h>

class FoodGate {
public:
    FoodGate();
    
    void open();
    void close();
    bool isOpen();
private:
    Servo servo;
    bool state;
}

#endif // FOODGATE_H