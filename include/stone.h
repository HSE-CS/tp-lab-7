// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/object.h"
#include "../include/common.h"
#include "../include/cell.h"

class Stone : public Object {
 public:
    explicit Stone(Cell* cell);
    ~Stone() {}
    void live() override;
    char getSymbol() override;

};

#endif  // INCLUDE_STONE_H_
