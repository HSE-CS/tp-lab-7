//  Copyright 2021 Kartseva Masha
#pragma once
#define PREY_H
#ifdef PREY_H
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "Common.h"
#include <iostream>
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
