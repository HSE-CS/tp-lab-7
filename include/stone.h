// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "object.h"
#include "common.h"
#include "cell.h"

class Stone : public Object {
 public:
  Stone(Cell* cell);
  ~Stone() {};
  void live();
  char getSymbol() override;
};

#endif  // INCLUDE_STONE_H_





