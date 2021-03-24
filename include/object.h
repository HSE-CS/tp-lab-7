// Copyright 2021 Kasyanov
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include <iostream>
#include "common.h"

#define STONE_N '#'
#define CORAL_N '.'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType {STONE, CORAL, PREY, PREDATOR};

class Cell;
class Ocean;

class Object {
    friend std::ostream& operator<<(std::ostream& out, const Cell& cell);
    friend Ocean;

 protected:
    Cell *cell;
    ObjType type;
    int life;
    int progeny_time;

 public:
    explicit Object(Cell * = nullptr, ObjType = ObjType::CORAL);
    virtual void live() = 0;
    void setCell(Cell*);
};

#endif // INCLUDE_OBJECT_H_
