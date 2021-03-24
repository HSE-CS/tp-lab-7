// Copyright 2021 Kasyanov
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "object.h"

class Stone : public Object {
 public:
    explicit Stone(Cell* = nullptr);
    virtual void live();
};

#endif // INCLUDE_STONE_H_
