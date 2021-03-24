// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_
#include <iostream>
#include <string>
#include <vector>
#include "common.h"

class Cell;

class Object {
 protected:
    Cell* cell;
    ObjType type;
    bool dead;
 public:
    Object(ObjType type_, Cell* cell_): cell(cell_), type(type_), dead(false) {};
    virtual ~Object();
    virtual void live() = 0;
    void setCell(Cell*);
    virtual void move();
    void die();
    ObjType getType();
};
#endif  // INCLUDE_OBJECT_H_
