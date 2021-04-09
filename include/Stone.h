// Copyright 2021 Tyulin Igor

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#pragma once
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "Common.h"
class Stone : public Object {
    friend Cell;
 public:
    explicit Stone(Cell * c);
    ~Stone() {}
    void live();
    char getSymbol() override;
};

#endif  // INCLUDE_STONE_H_
