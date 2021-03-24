//Copyright 2021 Dumarevskaya
#ifndef INCLUDE_STONE_H
#define INCLUDE_STONE_H

#include "Object.h"
#include "Cell.h"

class Stone : public Object {
 public:
  explicit Stone(Cell* cell) : Object(cell) {};
  ~Stone() {};
  void live() override;
};

#endif // INCLUDE_STONE_H
