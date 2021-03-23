// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include "../include/object.h"
#include "../include/cell.h"

class Prey : public Object {
 public:
    Prey(ObjType newObjType, Cell* cell);
    ~Prey();
    void live();
    void move();
    void breed();
};

#endif  // INCLUDE_PREY_H_
