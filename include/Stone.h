//  Copyright 2021 Kartseva Masha
#pragma once
#define INCLUDE_STONE_H 
#ifdef INCLUDE_STONE_H
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include "../include/common.h"
class Stone : public Object {
    friend Cell;
 public:
    explicit Stone(Cell* c);
    ~Stone() {}
    void live();
    char getSymbol() override;
};
#endif  // INCLUDE_STONE_H
