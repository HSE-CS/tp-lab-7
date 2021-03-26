// Copyright 2021 VladimirUspensky

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/object.h"

class Stone: public Object {
 public:
    explicit Stone(Cell* cell);
    ~Stone() override;
    void live() override;
};

#endif  // INCLUDE_STONE_H_
