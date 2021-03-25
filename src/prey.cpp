#include "prey.h"

#include <algorithm>
#include <cstdlib>

#include "world.h"

void Prey::update(World *world, int x, int y) {
  energy -= 1;
  reproduction_timer = std::max(reproduction_timer - 1, 0);
  if (energy == 0) {
    world->replace(nullptr, x, y);
    return;
  }
  int direction = std::rand() % 4;
  int end_direction = direction;
  do {
    switch (direction) {
      case MoveDirection::DOWN:
        if (y < world->getHeight() - 1 &&
            world->getObjectAt(x, y + 1) == nullptr) {
          if (reproduction_timer == 0) {
            world->replace(new Prey(reproduction_rate, lifetime), x, y + 1);
            reproduction_timer = reproduction_rate;
          } else {
            world->swap(x, y + 1, x, y);
          }
          return;
        }
        break;
      case MoveDirection::UP:
        if (y > 0 && world->getObjectAt(x, y - 1) == nullptr) {
          if (reproduction_timer == 0) {
            world->replace(new Prey(reproduction_rate, lifetime), x, y - 1);
            reproduction_timer = reproduction_rate;
          } else {
            world->swap(x, y - 1, x, y);
          }
          return;
        }
        break;
      case MoveDirection::LEFT:
        if (x > 0 && world->getObjectAt(x - 1, y) == nullptr) {
          if (reproduction_timer == 0) {
            world->replace(new Prey(reproduction_rate, lifetime), x - 1, y);
            reproduction_timer = reproduction_rate;
          } else {
            world->swap(x - 1, y, x, y);
          }
          return;
        }
        break;
      case MoveDirection::RIGHT:
        if (x < world->getWidth() - 1 &&
            world->getObjectAt(x + 1, y) == nullptr) {
          if (reproduction_timer == 0) {
            world->replace(new Prey(reproduction_rate, lifetime), x + 1, y);
            reproduction_timer = reproduction_rate;
          } else {
            world->swap(x + 1, y, x, y);
          }
          return;
        }
        break;
      default:
        break;
    }
    direction = (direction + 1) % 4;
  } while (end_direction != direction);
}
