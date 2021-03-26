// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "object.h"

class Stone : public Object {
 public:
  Stone(Cell *_cell = nullptr) : Object(_cell) { type = STONE; }
  void live() override;
};

#endif  // INCLUDE_STONE_H_
