// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "object.h"

class Stone : public Object {
 public:
  Stone(Cell* newCell);
  ~Stone() = default;
  virtual void live();
  virtual void die();
};

#endif  // INCLUDE_STONE_H_
