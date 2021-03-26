// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/cell.h"

class Stone : public Object {
 public:
    explicit Stone(Cell*, char);
    bool live() override {
        return true;
    };
};

#endif  // INCLUDE_STONE_H_
