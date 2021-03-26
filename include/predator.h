// Copyright 2021 VladimirUspensky

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "prey.h"

class Predator: public Prey {
 public:
    explicit Predator(Cell* c);
    void live() override;
    void hunt();
};


#endif  // INCLUDE_PREDATOR_H_