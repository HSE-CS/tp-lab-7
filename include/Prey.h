// Copyright 2021 by Sid

#ifndef Prey_h
#define Prey_h
#include "Object.h"

class Prey: public Object {
protected:
    int reproduceTime = PREY_REPRODUCE_PERIOD;
public:
    Prey(Cell* cell, int lifetime = PREY_LIFETIME) : Object(cell) { this->lifetime = lifetime;
    }

    char getSymbol() { return PREY_CHAR; }
    void setLife(int lifetime) { this->lifetime = lifetime; }
    bool live();
    virtual void move();
    void reproduce();
};

#endif /* Prey_h */
