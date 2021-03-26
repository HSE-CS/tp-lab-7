//  Copywright 2021 Kartseva Masha
#pragma once
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"
#define PREDATOR_H
#ifdef PREDATOR_H
class Predator : public Object {
    friend Cell;
public:
    Predator(Cell* c);
    ~Predator() {};
    void copulation();
    void live();
    void move();
    bool eat();
    char getSymbol() override;
};
#endif  // PREDATOR_H
