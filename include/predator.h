// Copyright <Roman Balayan> @ 2021

#pragma once

#include <memory>

#include "../include/prey.h"

class Predator : public Prey {
 public:
    explicit Predator(std::weak_ptr<Cell> cell = std::weak_ptr<Cell>());
    void live();
    void reproduction();
    void eat();
 private:
    unsigned int health;
};
