// Copyright 2021 Elise
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/object.h"
#include "../include/common.h"
#include "../include/ocean.h"
#include "../include/cell.h"

class Prey : public Object {
 protected:
  unsigned int time;

 public:
  explicit Prey(Cell* cell);
  void live() override;
  void sail();
  void babies();
};

#endif  // INCLUDE_PREY_H_
