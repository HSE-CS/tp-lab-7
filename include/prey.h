// Copyright [2020] <Olesya Nikolaeva>

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "object.h"

class Prey : public Object {
protected:
    int lifetime = 0;
    int timetospawn = 0;
public:
    explicit Prey(Cell* cell,
                  ObjType type = ObjType::PREY)
    : Object(type, cell) {}
    ~Prey() {}
    void live();
    void move();
    void spawn();
};


#endif  // INCLUDE_PREY_H_
