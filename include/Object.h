//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_OBJECT_H
#define INCLUDE_OBJECT_H

#include "common.h"
#include "cell.h"

#define STONE_SYM '#'
#define CORAL_SYM '*'
#define PREY_SYM 'f'
#define PREDATOR_SYM 'S'

enum class ObjType {STONE, CORAL, PREY, PREDATOR};

class Cell;

class Object {
 protected:
    Cell *cell;

 public:
    explicit Object(Cell* = nullptr);
    virtual ~Object();
    virtual void live() = 0;
    void setCell(Cell*);
};

#endif  //  INCLUDE_OBJECT_H
