// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "object.h"

class Prey : public Object, public Alive {
 private:
  void move() override;
  void reproduce() override;

 public:
  explicit Prey(Cell* = nullptr);
  void live() override;
};

#endif  // INCLUDE_PREY_H_
