//  Copyright 2021 Kartseva Masha
#pragma once
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include "../include/common.h"
#define STONE_H
#ifdef STONE_H
class Stone : public Object {
    friend Cell;
 public:
    Stone(Cell* c);
    ~Stone() {}
    void live();
    char getSymbol() override;
};
#endif  // STONE_H
