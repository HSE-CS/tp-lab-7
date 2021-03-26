//  Copyright 2021 Nikita Naumov

#ifndef INCLUDE_OBJECT_H
#define INCLUDE_OBJECT_H

#include "../include/common.h"
#define NONE_SYM '.'
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
    ObjType type = ObjType::NONE;  //  None

 public:
    explicit Object(Cell* objToSet);
    ~Object();
    virtual void live() = 0;
    void setCell(Cell* objToSet);
    virtual void  setType() = 0;
    ObjType getType();

    void setObjectToCell(Object* object) {}
};

#endif  //  INCLUDE_OBJECT_H
