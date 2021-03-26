// Copyright 2021 by me
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "Object.h"

class Cell;

class Stone : public Object {
 public:
  explicit Stone(Cell *cell_);
  void live() override;
};

#endif  // INCLUDE_STONE_H_
