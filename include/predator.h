// Copyright 2021 LongaBonga

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "cell.h"
#include "common.h"
#include "object.h"
#include "ocean.h"
class Predator : public Object {
  friend Cell;

 public:
  explicit Predator(Cell *c);
  ~Predator() {}
  void copulation();
  void live() override;
  void move();
  bool eat();
  char getSymbol() override;
};

#endif  // INCLUDE_PREDATOR_H_
