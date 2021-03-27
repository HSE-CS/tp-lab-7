// Copyright 2021 Lab_7 TiNa
#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include <list>

#include "prey.h"
#include "cell.h"
#include "common.h"

class Predator : public Prey {
 private:
  int counter_of_eaten;

 public:
  explicit Predator(Cell* cell);
  void live() override;
  void reproduction();

};

#endif  // INCLUDE_PREDATOR_H_
