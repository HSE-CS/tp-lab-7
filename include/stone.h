// Copyright 2021 Smirnov Grigory
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "object.h"

class Stone : Object {
 protected:
  int durability = 100;
 public:
   Stone(Cell* c = nullptr);
   void live();
};

#endif // INCLUDE_STONE_H_