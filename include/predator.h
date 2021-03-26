// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_PREDATOR_H_
#define INCLUDE_PREDATOR_H_

#include "../include/object.h"

class Predator : public Object {
 public:
  explicit Predator(Cell *cell, ObjType ot) : 
	  Object(cell, ot), 
	  obj_type(ot) {};

  void live() override;
  void eat();
  void move();

 private:
  ObjType obj_type;
};


#endif  // INCLUDE_PREDATOR_H_
