// Copyright 2021 VadMack

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "cell.h"
class Object;
class Prey : public Object {
 private:
  size_t timeToDie;
  size_t timeToReproduce;
 public:
  Prey(Cell* cell);
  void live() override;
  void reproduce();

};

#endif  // INCLUDE_PREY_H_
