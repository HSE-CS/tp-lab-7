// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "prey.h"

class Predator : public Prey {
protected:
    int lifetime = 0;
    int timetospawn = 0;
    int hungrydays = 0;
public:
    explicit Predator(Cell* cell,
                      ObjType type = ObjType::PREDATOR)
    : Prey(cell) {
        hungrydays = 0;
    }
    ~Predator() {}
    void live();
    void move();
    void eat();
    void spawn();
};


#endif  // INCLUDE_PREDATOR_H_

