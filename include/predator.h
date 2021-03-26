// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "prey.h"

class Predator: public Prey {
 public:
    explicit Predator(Cell* _cell = nullptr,
                   NATURE _nature = NATURE::PREDATOR,
                   unsigned int _age = 0);
    ~Predator() override;
    void live() override;
    bool eat();
};

#endif  // INCLUDE_PREDATOR_H_
