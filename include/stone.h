// Copyright 2021 Ilya Urtyukov
#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_
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
