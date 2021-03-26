//  Copyright 2021 Kartseva Masha
#pragma once
#define PREY_H
#ifdef PREY_H
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include "../include/common.h"
class Cell;
class Ocean;
class Prey : public Object {
    friend Cell;
    friend Ocean;
 public:
    explicit Prey(Cell* c);
    ~Prey() {}
    void live();
    void move();
    void copulation();
    char getSymbol() override;
};
#endif  // PREY_H
