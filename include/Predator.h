// Copyright 2021 by Sid

#ifndef Predator_h
#define Predator_h
#include "Prey.h"

class Predator: public Prey {

public:
    Predator(Cell* cell, int lifetime = PREDATOR_LIFETIME) : Prey(cell, lifetime) {}

    char getSymbol() { return PREDATOR_CHAR; }
    bool live();
//	void move();
    void reproduce();
    bool eat();
};

#endif /* Predator_h */