// Copyright <Roman Balayan> @ 2021

#pragma once

#include "object.h"

class Stone : public Object {
public:
    Stone(std::weak_ptr<Cell> cell = std::weak_ptr<Cell>());
    void live();
};
