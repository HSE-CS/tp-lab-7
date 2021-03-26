// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include <vector>
#include "../include/object.h"
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

#endif  // INCLUDE_PREY_H_
