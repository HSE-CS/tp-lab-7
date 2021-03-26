// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_PREY_H
#define INCLUDE_PREY_H

#include "../include/object.h"
#include <vector>
using std::vector;

class Prey : public Object {
 protected:
    int iterCounter;
 public:
    Prey(Cell* cell, char sign);
    ~Prey() override = default;
    bool live() override;
    virtual void reproduce(vector<Cell*>*, int, Object*);
};

#endif  // INCLUDE_PREY_H
