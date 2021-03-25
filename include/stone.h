// Copyright 2021 Kriss Egorova


#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include <string>
#include <vector>
#include <iostream>

#include "object.h"

class Stone : public Object {
public:
    explicit Stone(Cell* startCell) :
        Object(ObjType::CORAL, startCell) {}
    ~Stone() override;
    void live() override;
    void death() override;
};

#endif  // INCLUDE_STONE_H_