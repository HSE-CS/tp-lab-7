// Copyright 2021 Smirnov Grigory
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "../include/prey.h"

class Cell;
class Predator : public Prey {
 protected:
   int satiety = 15;
 public:
  Predator(Cell* c = nullptr);
  Cell* devour();
  virtual void live();
};

#endif // INCLUDE_PREDATOR_H_