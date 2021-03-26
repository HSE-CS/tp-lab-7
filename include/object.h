// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/common.h"

#define STONE_SYMBOL '#'
#define CORAL_SYMBOL '*'
#define PREY_SYMBOL 'f'
#define PREDATOR_SYMBOL 'S'

enum class ObjType { STONE, PREY, PREDATOR };

class Cell;
class Object {
 protected:
    Cell* cell;
    char sign;
 public:
    explicit Object(Cell*, char);
    virtual ~Object();
    virtual bool live() = 0;
    void setCell(Cell*);
    Cell* getCell();
    char getSign();
};

#endif  // INCLUDE_OBJECT_H_
