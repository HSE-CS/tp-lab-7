// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "../include/prey.h"

class Predator : public Prey {
 public:
  explicit Predator(Cell* newCell);
  ~Predator() = default;
  virtual bool tryToMove();
  virtual void live();
};

#endif  // INCLUDE_PREDATOR_H_
