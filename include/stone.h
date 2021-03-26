// Copyright 2021 Artem Danyaev
#pragma once

#include "../include/object.h"

class Stone : public Object {
 public:
  explicit Stone(Cell* c = nullptr);
  void live();
};
