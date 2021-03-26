// Copyright 2020 PollyllyZh

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include "../include/common.h"

class Cell;
class Ocean;
class Prey : public Object {
public:
    Prey(Cell* cell) : Object(cell) {
        obj_type = ObjType::PREY;
        lifetime = prey_lim;
        repro_time = reproduce_time;
    }
    bool live() override;
    void move() override;
    void reproduce() override;
    char get_symbol() override;
};
#endif  // INCLUDE_PREY_H_