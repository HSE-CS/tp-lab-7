#pragma once

class World;

enum ObjectType { STONE, PREY_FISH, PREDATOR_FISH };

class Object {
 public:
  explicit Object(ObjectType type) : type(type){};
  ObjectType type;
  virtual ~Object() = default;
  virtual void update(World *world, int x, int y) = 0;
};
