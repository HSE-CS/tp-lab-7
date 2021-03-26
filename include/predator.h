// Copyright 2020 PollyllyZh
#pragma once
#include "common.h"
#include "ocean.h"
#include "object.h"
#include "cell.h"

class Predator : public Object {
private:
    bool yum = false;
	
public:
    Predator(Cell* cell) : Object(cell) {
        obj_type = ObjType::PREDATOR;
        lifetime = predator_lim;
        repro_time = reproduce_time;
    }
    bool live() override;
    void move() override;
    void reproduce() override;
    char get_symbol() override;
    bool eatTo();
};
