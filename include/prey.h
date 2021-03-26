// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"
#include "../include/common.h"


class Prey : public Object {
    friend Cell; friend Ocean;
 public:
    explicit Prey(Cell* cell);
    ~Prey() {}
    void live();
    void move();
    void makeDescendant();
    char getSymbol() override;
};

#endif  // INCLUDE_PREY_H_