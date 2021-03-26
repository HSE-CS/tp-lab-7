// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_PREDATOR_H
#define INCLUDE_PREDATOR_H

#include "../include/prey.h"

class Predator : public Prey {
 protected:
    int itersSinceEating;
 public:
    Predator(Cell* cell, char sign);
    ~Predator() override = default;
    bool live() override;
    void hunt();
};

#endif  // INCLUDE_PREDATOR_H
