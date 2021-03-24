// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

//#include "Object.h"
#include "Cell.h"

class Cell;
class Object;

class Stone : public Object {
 public:
  explicit Stone(Cell* cell) : Object(cell) {}
  ~Stone() {}
  void live() override;
};

#endif  // INCLUDE_STONE_H_
