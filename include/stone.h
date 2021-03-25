#pragma once
#include "object.h"
#include "world.h"

class Stone : public Object {
 public:
  Stone() : Object(ObjectType::STONE){};
  void update(World* world, int x, int y) override{};
};
