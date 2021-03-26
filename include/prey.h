// Copyright 2020 Osmanov Islam
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include <iostream>
#include <string>
#include "../include/object.h"

class Prey : public Object {
 protected:
    int heal;
    int produceCounter = 0;
    int produceRate;
 public:
    Prey(Cell* cell1, int health = 3, int beed = 2);
    ~Prey();
    void live() override;
    void move() override;
    virtual void produce();
    void setCell(Cell*);
};
#endif // INCLUDE_PREY_H_
