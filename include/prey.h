// Copyright by Egor Bodrov 2021

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/object.h"

class Prey : public Object {
 protected:
  unsigned timeToDie;
  unsigned timeToReproduce;

 public:
  explicit Prey(Cell* cell);

  void live() override;

  virtual void spawn();
};

#endif  // INCLUDE_PREY_H_
