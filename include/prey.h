#pragma once
#include "living.h"
#include "world.h"

const int PREY_MIN_LIFETIME = 3;
const int PREY_MAX_LIFETIME = 30;
const int PREY_MIN_REPRODUCTION_RATE = 7;
const int PREY_MAX_REPRODUCTION_RATE = 20;

class Prey : public Living {
  int reproduction_timer;
  int reproduction_rate;

 public:
  Prey(int reproduction_rate, int lifetime)
      : Living(ObjectType::PREY_FISH, lifetime),
        reproduction_timer(reproduction_rate),
        reproduction_rate(reproduction_rate){};
  void update(World *world, int x, int y) override;
  ~Prey() override = default;
};
