// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "object.h"

class Prey : public Object {
protected:
    int lifetime = LIFE_TIME_PREY;
    int timetospawn = TIME_TO_SPAWN_PREY;
public:
    explicit Prey(Cell* cell, ObjType type = ObjType::PREY) : Object(type, cell) {}
    ~Prey() {}
    void live();
    void move();
    void spawn();
    Cell* getCell();
};


#endif  // INCLUDE_PREY_H_
