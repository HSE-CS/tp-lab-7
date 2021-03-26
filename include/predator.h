// Copyright 2020 PollyllyZh

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "../include/common.h"
#include "../include/ocean.h"
#include "../include/object.h"
#include "../include/cell.h"

class Predator : public Object {
 private:
    bool yum = false;

 public:
    explicit Predator(Cell* cell) : Object(cell) {
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
#endif  // INCLUDE_PREDATOR_H_
