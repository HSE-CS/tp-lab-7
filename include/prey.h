// Copyright 2021 Kasyanov
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "object.h"

class Prey : public Object {
 public:
    explicit Prey(Cell* = nullptr);
    virtual void live();
};

#endif // INCLUDE_PREY_H_
