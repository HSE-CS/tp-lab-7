// Copyright 2020 GHA Test Team
#ifndef _STONE_H_
#define _STONE_H_
#include "object.h"


class Stone : public Object {
 public:
  Stone();
  ~Stone() = default;
  Stone(const Stone&) = default;
  Stone& operator=(const Stone&) = default;
  void live();
};
#endif  // INCLUDE_STONE_H_
