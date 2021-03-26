#pragma once
#include "living.h"
#include "world.h"

const int PREY_MIN_LIFETIME = 15;
const int PREY_MAX_LIFETIME = 30;
const int PREY_MIN_REPRODUCTION_RATE = 4;
const int PREY_MAX_REPRODUCTION_RATE = 12;

class Prey : public Living {
 protected:
  using ExtraData = struct {
    int last_free_x;
    int last_free_y;
    int neighbors;
  };
  int reproduction_timer;
  int reproduction_rate;
  bool actOnDirection(World& world, int self_x, int self_y, int target_x,
                      int target_y, void* extra_data) override;

 public:
  explicit Prey(int reproduction_rate = genReproductionRate(),
                int lifetime = genLifetime())
      : Living(ObjectType::PREY_FISH, lifetime),
        reproduction_timer(reproduction_rate),
        reproduction_rate(reproduction_rate) {}
  ~Prey() override = default;
  void update(World& world, int x, int y) override;
  static int genReproductionRate();
  static int genLifetime();
};
