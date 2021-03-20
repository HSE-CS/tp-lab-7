// Copyright 2021 VadMack

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "prey.h"
#include "cell.h"
class Predator : public Prey {
 public:
  Predator(Cell *cell);
  bool live(){};
};

#endif  // INCLUDE_PREDATOR_H_
