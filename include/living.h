#pragma once
#include "object.h"
#include "world.h"

enum MoveDirection { UP, DOWN, LEFT, RIGHT };

class Living : public Object {
 protected:
  int energy;
  int lifetime;
  bool scanAdjacent(World& world, int x, int y, void* extra_data = nullptr);
  virtual bool actOnDirection(World& world, int self_x, int self_y,
                              int target_x, int target_y, void* extra_data) = 0;

 public:
  Living(ObjectType type, int lifetime)
      : Object(type), energy(lifetime), lifetime(lifetime) {}
};
