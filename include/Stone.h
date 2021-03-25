// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "Object.h"

class Stone : public Object {
 public:
  explicit Stone(Cell* cell) : Object(ObjType::STONE, cell) {}
  ~Stone() {}
  void live() override;
};

#endif  // INCLUDE_STONE_H_
