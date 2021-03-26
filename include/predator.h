// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "prey.h"

class Predator : public Prey {
 public:
  Predator(Cell* newCell);
  ~Predator() = default;
  virtual bool tryToMove();
  virtual void live();
};

#endif  // INCLUDE_PREDATOR_H_
