// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
#include <iostream>
#include <string>
#include <vector>
#include "object.h"

class Stone : public Object {
 protected:
    Cell* cell;
 public:
    Stone(Cell* c) :Object(ObjType::STONE, c) {
        cell = c;
    }
    ~Stone() override {};
    void live() override;
    void setCell(Cell*);
};
#endif  // INCLUDE_STONE_H_
