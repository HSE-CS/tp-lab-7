//  Copywright 2021 Kartseva Masha
#pragma once
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"
#define STONE_H
#ifdef STONE_H
class Stone : public Object {
    friend Cell;
public:
    Stone(Cell* c);
    ~Stone() {};
    void live();
    char getSymbol() override;
};
#endif  // STONE_H
