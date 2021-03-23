// Copyright 2021 Dmitry Vargin
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/common.h"

class Cell;

class Object {
 public:
    Cell *cell;
    unsigned int life_time;
    static const unsigned int std_life_time = 0;
    explicit Object(Cell * cell = nullptr);
    virtual ~Object();
    virtual void live() = 0;
    void setCell(Cell *c);
    Cell *getCell();
    virtual char getCharacter() { return 'O'; }
    virtual ObjectType getType() {return ObjectType::OBJECT; }
};

#endif  // INCLUDE_OBJECT_H_
