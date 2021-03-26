// Copyright 2020 Osmanov Islam

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include <vector>
#include <iostream>
#include <string>
#include "../include/prey.h"


class Predator: public Prey {
 protected:
    int eat;
 public:
    explicit Predator(Cell* cell1,
    int health = 3, int prod = 2, int need = 2);
    ~Predator();
    void produce() override;
    void live() override;
    void kill();
    void setCell(Cell*);
};

#endif  // INCLUDE_PREDATOR_H_
