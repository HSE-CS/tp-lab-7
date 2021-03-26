#include "prey.h"

#include <algorithm>
#include <cstdlib>

#include "world.h"

void Prey::update(World& world, int x, int y) {
  reproduction_timer = std::max(reproduction_timer - 1, 0);
  auto extra_data = ExtraData{-1, -1, 0};
  scanAdjacent(world, x, y, &extra_data);
  if (extra_data.last_free_x != -1) {
    if (reproduction_timer == 0) {
      if (extra_data.neighbors < 3) {
        world.replace(new Prey, extra_data.last_free_x, extra_data.last_free_y);
      }
      reproduction_timer = reproduction_rate;
    } else {
      world.swap(x, y, extra_data.last_free_x, extra_data.last_free_y);
    }
  }
}

bool Prey::actOnDirection(World& world, int, int, int target_x, int target_y,
                          void* extra_data) {
  auto extra = static_cast<ExtraData*>(extra_data);
  Object* selected = world.getObjectAt(target_x, target_y);
  if (selected == nullptr) {
    extra->last_free_x = target_x;
    extra->last_free_y = target_y;
  } else if (selected->type == ObjectType::PREY_FISH) {
    extra->neighbors += 1;
  }
  return false;
}

int Prey::genReproductionRate() {
  return PREY_MIN_REPRODUCTION_RATE +
         std::rand() %
             (PREY_MAX_REPRODUCTION_RATE - PREY_MIN_REPRODUCTION_RATE);
}

int Prey::genLifetime() {
  return PREY_MIN_LIFETIME +
         std::rand() % (PREY_MAX_LIFETIME - PREY_MIN_LIFETIME);
}
