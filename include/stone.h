// Copyright 2021 Krayushkina
#pragma once

#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include "../include/common.h"
class Stone : public Object {
    friend Cell;
 public:
    explicit Stone(Cell * c);
    ~Stone() {}
    void live();
    char getSymbol() override;
}
