// Copyright 2021 Igumnova Natasha
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include <iostream>
#include <string>
#include <vector>
#include "object.h"

class Prey : public Object {
 protected:
    int health;
    int multCounter = 0;
    int multiPoint;
 public:
    Prey(Cell* c,
        int health_ = 5, int multi_ = 3):
        Object(PREY, c),
        health(health_), multiPoint(multi_) {}
    ~Prey();
    void live() override;
    void move() override;
    virtual void multi();
    void setCell(Cell*);
};
#endif  // INCLUDE_PREY_H_
