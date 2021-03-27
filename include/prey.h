// Copyright 2021 Lab_7 TiNa
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include <list>

#include "common.h"
#include "prey.h"

class Prey : public Object {
 protected:
  int time_of_life;

 public:
  explicit Prey(Cell* cell);
  void live() override;
  void reproduction();
};

#endif  // INCLUDE_PREY_H_
