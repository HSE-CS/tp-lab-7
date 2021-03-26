// Copyright [2020] <Olesya Nikolaeva>

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType {STONE, PREY, PREDATOR};

class Cell;

class Object {
 protected:
    Cell *cell;

 public:
    explicit Object();
    virtual ~Object();
    virtual void live() = 0; // жизнь объекта
    void setCell(Cell*);
};
#endif
