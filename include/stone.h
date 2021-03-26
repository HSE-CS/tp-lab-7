#pragma once
#include "object.h"
#include "world.h"

class Stone : public Object {
 public:
  Stone() : Object(ObjectType::STONE) {}
  void update(World&, int, int) override {}
};
