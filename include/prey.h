// Copyright 2021 Shirokov Alexander

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/object.h"

class Prey : public Object {
 protected:
  unsigned timeToDie;
  unsigned timeToReproduce;

 public:
  const int preyLife = 5;
  const int preyReproduction = 2;
  explicit Prey(Cell* cell);
  void live() override;
  virtual void reproduce();
};

#endif
