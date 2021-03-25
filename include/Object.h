//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_OBJECT_H
#define INCLUDE_OBJECT_H

#include "../include/common.h"
#include "../include/cell.h"

#define STONE_SYM '#'
#define CORAL_SYM '*'
#define PREY_SYM 'f'
#define PREDATOR_SYM 'S'

enum class ObjType {
    NONE = -1,
    STONE = 0,
    CORAL = 1,
    PREY = 2,
    PREDATOR = 3};

class Cell;

class Object {
 protected:
    Cell *cell;
    ObjType type = static_cast<ObjType>(-1);  //  None

 public:
    explicit Object(Cell* objToSet) { this->cell = objToSet; };
    virtual ~Object() { this->cell = nullptr; };
    virtual void live() = 0;
    void setCell(Cell* objToSet) { this->cell = objToSet; };
    virtual void  setType() = 0;
    ObjType getType() { return this->type; };
};

#endif  //  INCLUDE_OBJECT_H
