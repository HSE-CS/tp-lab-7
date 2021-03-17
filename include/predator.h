// Copyright 2021 valvarl

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "prey.h"

class Predator: public Prey {
public:
    explicit Predator(Cell* _cell);
    void live() override;
    void hunt();
};


#endif  // INCLUDE_PREDATOR_H_
