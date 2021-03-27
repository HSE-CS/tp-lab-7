// Copyright 2021 Smirnov Grigory
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/object.h"

class Stone : public Object {
 protected:
  int durability = 100;
 public:
   Stone(Cell* c = nullptr);
   virtual void live();
};

#endif // INCLUDE_STONE_H_