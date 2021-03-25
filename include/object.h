// Copyright 2021 MalininDmitry

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_
#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'
#define NOTHING_N '.'

enum class ObjType {STONE, CORAL, PREY, PREDATOR, NOTHING};
class Cell;
class Object {
 protected:
    Cell *cell;
    ObjType type;
 public:
    explicit Object(Cell * = nullptr);
    Object(Cell * cell, ObjType type);
    virtual ~Object();
    virtual void live() = 0;  // жизнь объекта
    void setCell(Cell* cell);
    ObjType getType();
};
#endif  // INCLUDE_OBJECT_H_

