// Copyright 2021 VladimirUspensky

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/common.h"
#include "../include/object.h"

class Prey: public Object {
 public:
    explicit Prey(Cell * cell);
    ~Prey() override;
    void live() override;
    void move();
};

class Coral: public Prey {
 public:
    explicit Coral(Cell * cell);
    void live() override;
};

#endif  // INCLUDE_PREY_H_
