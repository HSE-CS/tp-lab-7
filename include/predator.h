// Copyright by Egor Bodrov 2021

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "../include/prey.h"

class Predator : public Prey {
 private:
  unsigned eaten;

 public:
  explicit Predator(Cell* cell);

  void live() override;

  void spawn() override;
};

#endif  // INCLUDE_PREDATOR_H_
