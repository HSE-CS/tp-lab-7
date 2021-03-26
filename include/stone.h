// Copyright 2020 S. BOR
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "./cell.h"

class Stone : public Object {
 public:
  void nextTurn() override;
  void printSymb() override;
};

#endif  // INCLUDE_STONE_H_

