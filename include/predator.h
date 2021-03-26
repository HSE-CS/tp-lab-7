// Copyright [2020] <Olesya Nikolaeva>

#ifndef _PREDATOR_H_
#define _PREDATOR_H_

#include "prey.h"

class Predator : public Prey {
protected:
    int lifetime = LIFE_TIME_PREDATOR;
    int timetospawn = TIME_TO_SPAWN_PREDATOR;
    int hungrydays;
public:
    explicit Predator(Cell* cell, ObjType type = ObjType::PREY) : Prey(cell) {
        hungrydays = 0;
    }
    ~Predator() {}
    void live();
    void move();
    void eat();
    void spawn();
    Cell* getCell();
};


#endif  // INCLUDE_PREDATOR_H_

