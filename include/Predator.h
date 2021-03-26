// Copyright 2021 Krayushkina
#pragma once

#include "../include/Object.h"
#include "../include/Cell.h"
#include "../include/Ocean.h"
#include "../include/common.h"
class Predator : public Object {
    friend Cell;
 public:
    Predator(Cell * c);
    ~Predator() {}
    void copulation();
    void live();
    void move();
    bool eat();
    char getSymbol() override;
};
