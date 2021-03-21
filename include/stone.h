// Copyright 2020 GHA Test Team
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
#include "../include/object.h"


class Stone : public Object {
 public:
  Stone();
  ~Stone() = default;
  Stone(const Stone&) = default;
  Stone& operator=(const Stone&) = default;
  void live();
};
#endif  // INCLUDE_STONE_H_
