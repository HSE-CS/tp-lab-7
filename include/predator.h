// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "object.h"

class Predator : public Object, public Alive {
 private:
  bool isHungry;

  void eat();
  void move() override;
  void reproduce() override;

 public:
  explicit Predator(Cell* = nullptr);
  void live() override;
};

#endif  // INCLUDE_PREDATOR_H_
