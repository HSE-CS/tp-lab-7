// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include "object.h"
#include "cell.h"

class Prey : public Object {
public:
    Prey(ObjType newObjType, Cell* cell);
    ~Prey();
    void live();
    void move();
    void breed();
};

#endif 