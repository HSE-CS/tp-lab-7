// Copyright 2021 MalininDmitry

#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'
#define NOTHING_N '.'

enum class ObjType {STONE,CORAL,PREY,PREDATOR,NOTHING};

class Cell;
class Object
{
protected:
    Cell *cell;
    ObjType type;
public:
    Object(Cell * = nullptr);
    Object(Cell * cell, ObjType type);
    virtual ~Object();
    virtual void live() = 0; // жизнь объекта
    void setCell(Cell* cell);
    ObjType getType();
};
#endif
