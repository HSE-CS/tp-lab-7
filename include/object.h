// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/common.h"

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

class Cell;
class Object {
 protected:
    Cell* cell;
 public:
    explicit Object(Cell* = nullptr);
    virtual ~Object();
    Cell* getCell();
    void setCell(Cell* cell);
    virtual void live() = 0;
    virtual void die() = 0;
    virtual char getSymbol() = 0;
};
#endif  // INCLUDE_OBJECT_H_
