#pragma once
#include "living.h"
#include "world.h"

const int PREDATOR_MIN_LIFETIME = 10;
const int PREDATOR_MAX_LIFETIME = 20;

class Predator : public Living {
 protected:
  using ExtraData = struct {
    int last_free_x;
    int last_free_y;
  };
  bool satiated = false;
  bool actOnDirection(World &world, int self_x, int self_y, int target_x,
                      int target_y, void *extra_data) override;

 public:
  explicit Predator(int lifetime = genLifetime())
      : Living(ObjectType::PREDATOR_FISH, lifetime) {}
  void update(World &world, int x, int y) override;
  bool isSatiated() const { return satiated; }
  static int genLifetime();
};
