#include "predator.h"

#include <cstdlib>

bool Predator::actOnDirection(World& world, int self_x, int self_y,
                              int target_x, int target_y, void* extra_data) {
  auto extra = static_cast<ExtraData*>(extra_data);
  Object* selected = world.getObjectAt(target_x, target_y);
  if (selected == nullptr) {
    if (satiated) {
      world.replace(new Predator, target_x, target_y);
      satiated = false;
      return true;
    } else {
      extra->last_free_x = target_x;
      extra->last_free_y = target_y;
    }
  } else if (selected->type == ObjectType::PREY_FISH && !satiated) {
    world.replace(nullptr, target_x, target_y);
    energy += 5;
    satiated = true;
    return true;
  }
  return false;
}

void Predator::update(World& world, int x, int y) {
  auto extra_data = ExtraData{-1, -1};
  if (!scanAdjacent(world, x, y, &extra_data) && extra_data.last_free_x >= 0) {
    world.swap(extra_data.last_free_x, extra_data.last_free_y, x, y);
  }
}

int Predator::genLifetime() {
  return PREDATOR_MIN_LIFETIME +
         std::rand() % (PREDATOR_MAX_LIFETIME - PREDATOR_MIN_LIFETIME);
}
