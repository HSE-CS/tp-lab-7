// Copyright Mushka Nikita 2021

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "object.h"
#include "cell.h"

class Prey : public Object {
protected:
    unsigned int deathCounter;
    unsigned int birthCounter;
public:
    explicit Prey(Cell *cell);

    void step() override;

    virtual void giveBirth();
};

#endif  // INCLUDE_PREY_H_