// Copyright 2021 Khoroshavina Ekaterina
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_
#include "../include/object.h"
#include "../include/cell.h"

class Predator : public Object {
 protected:
    bool hungry;
 public:
    Predator(ObjType newObjType, Cell* cell);
    ~Predator() override;
    void live() override;
    void move();
    void eat();
    void breed();
};

#endif // INCLUDE_PREDATOR_H_
