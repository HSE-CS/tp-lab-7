// Copyright Mushka Nikita 2021

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "object.h"

class Stone : public Object {
public:
    explicit Stone(Cell *cell);

    void step() override;
};

#endif  // INCLUDE_STONE_H_