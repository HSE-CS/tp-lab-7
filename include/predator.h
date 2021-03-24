// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_
#include <iostream>
#include <string>
#include <vector>
#include "prey.h"

class Predator: public Prey {
 protected:
    int hunger = 0;
 public:
    Predator(Cell* c,
        int health_ = 5, int multi_ = 3, int hunger_ = 2) :
        Prey(c, health_, multi_), hunger(hunger_) {
        this->type = PREDATOR;
    }
    ~Predator();
    void live() override;
    void eat();
    void multi() override;
    void setCell(Cell*);
};
#endif  // INCLUDE_PREDATOR_H_
