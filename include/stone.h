// Copyright 2021 mkhorosh

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "object.h"

class Stone : public Object {
 public:
  Stone(ObjType type, Cell *cell);
  ~Stone();
  void live() override;
};

#endif  // INCLUDE_STONE_H_
