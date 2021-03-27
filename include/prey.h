// Copyright 2021 Smirnov Grigory
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/object.h"

class Cell;
class Prey : public Object {
protected:
  int liveCycle = 20;
  int reproductionCycle = 10;
public:
  Prey(Cell* c = nullptr);
  void resetReproductionCycle();
  Cell* toGo();
  virtual void live();
};

#endif // INCLUDE_PREY_H_