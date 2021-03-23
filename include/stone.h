// Copyright 2021 LongaBonga

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "cell.h"
#include "common.h"
#include "object.h"
#include "ocean.h"
class Stone : public Object {
  friend Cell;

 public:
  explicit Stone(Cell *c);
  ~Stone() {}
  void live() override;
  char getSymbol() override;
};
#endif  // INCLUDE_STONE_H_
