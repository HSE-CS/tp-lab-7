// Copyright 2021 VadMack

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "prey.h"
#include "cell.h"
class Predator : public Prey {
 public:
  Predator(Cell *cell);
  void live() override;
  void reproduce() override;
};

#endif  // INCLUDE_PREDATOR_H_
