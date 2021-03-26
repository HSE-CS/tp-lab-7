// Copyright 2021 Sozinov Kirill
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/object.h"

class Stone : public Object {
 public:
    explicit Stone(Cell* cell);
    void live();
};

#endif  // INCLUDE_STONE_H_
