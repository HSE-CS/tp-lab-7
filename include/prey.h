// Copyright 2021 Ryzhova
#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/object.h"

class Prey : public Object {
 public:
  explicit Prey(Cell* cell);
  void live() override;
  void propagation() override;
  void moving(Cell*) override;
};

#endif  // INCLUDE_PREY_H_
