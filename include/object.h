// Copyright 2020 PollyllyZh

#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "../include/common.h"

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, PREY, PREDATOR };

class Ocean;
class Cell;
class Object {
 protected:
    Cell* cell;
    uint lifetime;
    ObjType  obj_type;
    uint repro_time;

 public:
    Object(Cell* c) : cell(c) {}
    virtual ~Object() = default;
    virtual bool live() = 0;  // жизнь объекта
    virtual char get_symbol() = 0;
    virtual void move() {}
    virtual void reproduce() {}
    Cell* get_cell();
    ObjType get_type();
    void set_lifetime(uint lt);
};
#endif  // INCLUDE_OBJECT_H_
