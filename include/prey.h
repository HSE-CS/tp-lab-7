// Copyright 2021 Elise
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "object.h"
#include "common.h"
#include "ocean.h"
#include "cell.h"

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
