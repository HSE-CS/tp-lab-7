// Copyright <Roman Balayan> @ 2021

#pragma once

#include <memory>

#include "object.h"

class Prey : public Object {
public:
    Prey(std::weak_ptr<Cell> cell = std::weak_ptr<Cell>());
    void live();
    void reproduction();
protected:
    unsigned int health;
};

class Stone : public Object {
public:
    Stone(std::weak_ptr<Cell> cell = std::weak_ptr<Cell>());
    void live();
};
