// Copyright 2021 Vlad
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
#include "Object.h"
class Stone : public Object {
 public:
    explicit Stone(Cell* cell = nullptr) : Object(cell) {}
    void live() override;
    ~Stone() {}
};

#endif  // INCLUDE_STONE_H_
