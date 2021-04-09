// Copyright 2021 Tyulin Igor

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#pragma once
#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "Common.h"
class Cell;
class Ocean;
class Prey : public Object {
    friend Cell;
    friend Ocean;
 public:
    explicit Prey(Cell * c);
    ~Prey() {}
    void live();
    void move();
    void copulation();
    char getSymbol() override;
};

#endif  // INCLUDE_PREY_H_
