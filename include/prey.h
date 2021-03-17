// Copyright 2021 valvarl

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "common.h"
#include "object.h"

class Prey: public Object {
public:
    explicit Prey(Cell * _cell);
    void live() override;
    void move();
    ~Prey() override;
};

class Coral: public Prey {
public:
    explicit Coral(Cell * _cell);
    void live() override;
};

#endif  // INCLUDE_PREY_H_
