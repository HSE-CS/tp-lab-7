// Copyright 2020 PollyllyZh
#pragma once
#include "object.h"
#include "cell.h"
#include "ocean.h"
#include "common.h"

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
