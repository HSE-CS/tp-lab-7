// Copyright 2021 mkhorosh

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "object.h"
#include "cell.h"

class Predator : public Object {
 private:
  int hunger_timer;

 public:
  Predator(ObjType type, Cell *cell);
  ~Predator() override;
  void live() override;
};

#endif  // INCLUDE_PREDATOR_H_
