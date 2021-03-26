// Copyright 2021 Andrey Bakurskii

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/object.h"

class Stone : public Object {
 public:
  explicit Stone(Cell *cell, ObjType ot) :
	  Object(cell, ot),
	  obj_type(ot) {};

  void live() override;

 private:
  ObjType obj_type;
};


#endif  // INCLUDE_STONE_H_
