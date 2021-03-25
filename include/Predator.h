// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "Prey.h"

class Predator : public Prey {
 private:
  bool hungry;
 public:
  explicit Predator(Cell* cell) : Prey{ cell, ObjType::PREDATOR} {
    timeToReproduce = PREDATOR_BREED;
    lifeTime = PREDATOR_BREED;
    hungry = true;
  }
  ~Predator() {}
  void eat();
  void live() override;
};

#endif  // INCLUDE_PREDATOR_H_
