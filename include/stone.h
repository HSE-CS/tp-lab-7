// Copyright <Roman Balayan> @ 2021

#pragma once

#include <memory>

#include "../include/object.h"

class Stone : public Object {
 public:
    explicit Stone(std::weak_ptr<Cell> cell = std::weak_ptr<Cell>());
    void live();
};
