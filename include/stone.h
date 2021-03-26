// Copyright 2021 Shirokov Alexander

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/object.h"

class Stone : public Object {
 public:
  explicit Stone(Cell* cell);
  void live() override;
};

#endif  // INCLUDE_STONE_H_
