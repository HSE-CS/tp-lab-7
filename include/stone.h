// Copyright 2021 valvarl

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "object.h"

class Stone: public Object {
 public:
    explicit Stone(Cell* _cell);
    ~Stone() override;

    void live() override;
};

#endif  // INCLUDE_STONE_H_
