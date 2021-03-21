// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/object.h"

class Prey : public Object {
 protected:
    unsigned int leftTime;
    unsigned int leftToBirth;
 public:
    explicit Prey(Cell *cell);

    void live() override;

    virtual void giveBirth();
};

#endif  // INCLUDE_PREY_H_
