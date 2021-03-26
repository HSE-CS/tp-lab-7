// Copyright 2021 Krayushkina
#pragma once

#include "../include/Object.h"
#include "../include/Cell.h"
#include "../include/Ocean.h"
#include "../include/common.h"
class Stone : public Object {
    friend Cell;
 public:
    Stone(Cell * c);
    ~Stone() {}
    void live();
    char getSymbol() override;
}
