// Copyright 2021 Shirokov Alexander

#ifndef _STONE_H_
#define _STONE_H_

#include "../include/object.h"

class Stone : public Object {
 public:
  explicit Stone(Cell* cell);
  void live() override;
};

#endif
