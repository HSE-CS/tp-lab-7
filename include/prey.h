// Copyright 2021 mkhorosh

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/object.h"

class Prey : public Object {
 private:
  int life_timer;  // the number of iters it live

 public:
  Prey(ObjType type, Cell *cell);
  ~Prey();
  void live() override;
};

#endif  // INCLUDE_PREY_H_
