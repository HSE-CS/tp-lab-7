// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "object.h"

class Stone : public Object {
 public:
  explicit Stone(Cell* = nullptr);
  void live() override;
};

#endif  // INCLUDE_STONE_H_
