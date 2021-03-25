#pragma once
#include "living.h"
#include "world.h"

const int PREDATOR_MIN_LIFETIME = 10;
const int PREDATOR_MAX_LIFETIME = 20;

class Predator : public Living {
 private:
  bool satiated = false;

 public:
  explicit Predator(int lifetime)
      : Living(ObjectType::PREDATOR_FISH, lifetime){};
  void update(World* world, int x, int y) override;
  bool isSatiated() const { return satiated; };
  static int generateLifetime();
};
