// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_PREY_H_
#define INCLUDE_PREY_H_

#include "../include/object.h"

class Prey : public Object {
 public:
  explicit Prey(Cell *cell, ObjType ot) : Object(cell, ot), obj_type(ot){};

  void live() override;
  void move();

 private:
  ObjType obj_type;
};

#endif  // INCLUDE_PREY_H_
