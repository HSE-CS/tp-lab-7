//  Copywright 2021 Kartseva Masha
#pragma once
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"
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
