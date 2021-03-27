//  Copyright 2021 Kartseva Masha
#pragma once
#define STONE_H
#ifdef STONE_H
#include "Cell.h"
#include "Ocean.h"
#include "Common.h"
#include "Object.h"
class Stone : public Object {
    friend Cell;
 public:
    explicit Stone(Cell* c);
    ~Stone() {}
    void live();
    char getSymbol() override;
};
#endif  // STONE_H
