//  Copyright 2021 Kartseva Masha
#pragma once
#define PREDATOR_H
#ifdef PREDATOR_H
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include "../include/common.h"
class Predator : public Object {
    friend Cell;
 public:
    explicit Predator(Cell* c);
    ~Predator() {}
    void copulation();
    void live();
    void move();
    bool eat();
    char getSymbol() override;
};
#endif  // PREDATOR_H
