//  Copywright 2021 Kartseva Masha
#pragma once
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include "../include/common.h"
#define PREY_H
#ifdef PREY_H
class Cell;
class Ocean;
class Prey : public Object {
    friend Cell;
    friend Ocean;
 public:
    Prey(Cell* c);
    ~Prey() {};
    void live();
    void move();
    void copulation();
    char getSymbol() override;
};
#endif  // PREY_H
