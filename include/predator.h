// Copyright Mushka Nikita 2021

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "prey.h"

class Predator : public Prey {
private:
    unsigned int eatenPreys;
public:
    explicit Predator(Cell *cell);

    void step() override;

    void giveBirth() override;
};


#endif  // INCLUDE_PREDATOR_H_