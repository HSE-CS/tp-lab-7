// Copyright 2021 Shirokov Alexander

#ifndef INCLUDE_CORAL_H_
#define INCLUDE_CORAL_H_

#include "../include/object.h"

class Coral : public Object {
 protected:
  unsigned timeToDie;
  unsigned timeToReproduce;

 public:
  const int coralLife = 10;
  const int coralReproduction = 6;
  explicit Coral(Cell* cell);
  void live() override;
  virtual void reproduce();
};

#endif  // INCLUDE_CORAL_H_
