//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_STONE_H_
#define INCLUDE_STONE_H_

#include <string>
#include <vector>
#include <iostream>

#include "../include/object.h"

class Stone : public Object {
 public:
  explicit Stone(Cell* startCell):
  Object(ObjType::CORAL, startCell) {}
  ~Stone() override;
  void live() override;
  void death() override;
};

#endif  // INCLUDE_STONE_H_
