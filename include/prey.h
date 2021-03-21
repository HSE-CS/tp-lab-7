// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "object.h"

class Prey : public Object {
 protected:
    size_t leftTime;
    size_t leftToBirth;
 public:
    explicit Prey(Cell *cell);

    void live() override;

    virtual void giveBirth();
};

#endif  // INCLUDE_PREY_H_
