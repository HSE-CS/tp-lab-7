// Copyright 2021 Kasyanov
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "object.h"

class Predator : public Object {
 public:
    explicit Predator(Cell* = nullptr);
    virtual void live();
};

#endif // INCLUDE_PREDATOR_H_
