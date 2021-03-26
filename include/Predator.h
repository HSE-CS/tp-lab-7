//  Copyright 2021 Kartseva Masha
#pragma once
#define PREDATOR_H
#ifdef PREDATOR_H
#include "Cell.h"
#include "Ocean.h"
#include "Object.h"
#include "Common.h"
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
#endif // PREDATOR_H
