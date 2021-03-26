// Copyright 2021 Krayushkina
#pragma once

#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include "../include/common.h"
class Predator : public Object {
    friend Cell;
 public:
    explicit Predator(Cell * c);
    ~Predator() {}
    void copulation();
    void live();
    void move();
    bool eat();
    char getSymbol() override;
};
