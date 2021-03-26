// Copyright 2021 Bogomazov
#ifndef _PREDATOR_H_
#define _PREDATOR_H_

#include "../include/prey.h"

class Predator : public Prey {
 private:
    unsigned int number_of_fish_eaten;
 public:
    explicit Predator(Cell* cell);
    void live() override;
    void breeding();
};

#endif  //  PREDATOR_H_
