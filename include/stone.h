// Copyright 2021 Schenikova
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include "./cell.h"

class Stone : public Object {
 public:
  void live() override;
  void printInfo() override;
};

#endif  // INCLUDE_STONE_H_
