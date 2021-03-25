#pragma once
#include "object.h"

enum MoveDirection { UP, DOWN, LEFT, RIGHT };

class Living : public Object {
 protected:
  int energy;
  int lifetime;

 public:
  Living(ObjectType type, int lifetime)
      : Object(type), energy(lifetime), lifetime(lifetime){};
};
