// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/object.h"

class Object;

class Stone : public Object {
 public:
  explicit Stone(Cell *_cell = nullptr) : Object(_cell) { type = STONE; }
  void live() override;
};

#endif  // INCLUDE_STONE_H_
