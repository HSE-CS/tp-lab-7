// Copyright 2020 Osmanov Islam

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include <string>
#include "../include/common.h"
class Cell;
class Object {
 protected:
    Cell* cell;
    ObjType objType;
    bool isAlive;
 public:
    Object(ObjType objType, Cell* cell1);
    virtual ~Object();
    void alive();
    virtual void move();
    ObjType getType();
    virtual void live() = 0;
    void setCell(Cell*);
};

#endif  // INCLUDE_OBJECT_H_
