// Copyright by Egor Bodrov 2021

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "../include/object.h"

class Stone : public Object {
 public:
  explicit Stone(Cell* cell);

  void live() override;

};



#endif  // INCLUDE_STONE_H_
