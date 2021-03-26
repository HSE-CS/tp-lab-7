// Copyright 2020 Osmanov Islam

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "../include/object.h"

class Stone : public Object {
 protected:
    Cell* cell;
 public:
    void live() override;
    explicit Stone(Cell* cell1);
    ~Stone() override {};
    void setCell(Cell*);
};

#endif  // INCLUDE_STONE_H_
