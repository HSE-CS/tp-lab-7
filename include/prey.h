// Copyright 2021 VadMack

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/cell.h"
#include "../include/object.h"
class Object;
class Prey : public Object {
 protected:
  size_t timeToDie;
  size_t timeToReproduce;
 public:
  explicit Prey(Cell* cell);
  void live() override;
  virtual void reproduce();
  size_t GetTimeToDie() const;
};

#endif  // INCLUDE_PREY_H_
