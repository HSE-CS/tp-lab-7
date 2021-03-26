// Copyright 2021 Shirokov Alexander

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "../include/prey.h"

class Predator : public Prey {
 private:
  unsigned eaten;

 public:
  const int predatorLife = 5;
  const int predatorReproduction = 3;
  const int predatorUpgrade = 2;
  explicit Predator(Cell* cell);
  void live() override;
  void reproduce() override;
};

#endif  // INCLUDE_PREDATOR_H_
