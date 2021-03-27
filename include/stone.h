// Copyright 2021 Lab_7 TiNa
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include <list>

#include "cell.h"
#include "common.h"
#include "prey.h"

class Stone : public Object {
 public:
  explicit Stone(Cell* cell);
  void live() override;
};

#endif  // INCLUDE_STONE_H_
