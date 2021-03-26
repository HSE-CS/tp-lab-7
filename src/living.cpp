#include "living.h"

#include <cstdlib>

bool Living::scanAdjacent(World& world, int x, int y, void* extra_data) {
  energy -= 1;
  if (energy == 0) {
    world.replace(nullptr, x, y);
    return true;
  }
  auto direction = static_cast<MoveDirection>(std::rand() % 4);
  MoveDirection end_direction = direction;
  do {
    switch (direction) {
      case MoveDirection::DOWN:
        if (y < world.getHeight() - 1) {
          if (actOnDirection(world, x, y, x, y + 1, extra_data)) return true;
        }
        break;
      case MoveDirection::UP:
        if (y > 0) {
          if (actOnDirection(world, x, y, x, y - 1, extra_data)) return true;
        }
        break;
      case MoveDirection::LEFT:
        if (x > 0) {
          if (actOnDirection(world, x, y, x - 1, y, extra_data)) return true;
        }
        break;
      case MoveDirection::RIGHT:
        if (x < world.getWidth() - 1) {
          if (actOnDirection(world, x, y, x + 1, y, extra_data)) return true;
        }
        break;
    }
    direction = static_cast<MoveDirection>((direction + 1) % 4);
  } while (end_direction != direction);
  return false;
}
