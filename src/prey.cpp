#include "prey.h"

#include <algorithm>
#include <cstdlib>

#include "world.h"

void Prey::update(World* world, int x, int y) {
  energy -= 1;
  reproduction_timer = std::max(reproduction_timer - 1, 0);
  if (energy <= 0) {
    world->replace(nullptr, x, y);
    return;
  }
  int direction = std::rand() % 4;
  int end_direction = direction;
  int neighbors = 0;
  do {
    if (neighbors >= 3) {
      energy /= 2;
    }
    switch (direction) {
      case MoveDirection::DOWN:
        if (y < world->getHeight() - 1) {
          Object* selected = world->getObjectAt(x, y + 1);
          if (selected == nullptr) {
            if (reproduction_timer == 0) {
              world->replace(new Prey(Prey::generateReproductionRate(),
                                      Prey::generateLifetime()),
                             x, y + 1);
              reproduction_timer = reproduction_rate;
            } else {
              world->swap(x, y + 1, x, y);
            }
            return;
          } else if (selected->type == PREY_FISH) {
            neighbors += 1;
          }
        }
        break;
      case MoveDirection::UP:
        if (y > 0) {
          Object* selected = world->getObjectAt(x, y - 1);
          if (selected == nullptr) {
            if (reproduction_timer == 0) {
              world->replace(new Prey(Prey::generateReproductionRate(),
                                      Prey::generateLifetime()),
                             x, y - 1);
              reproduction_timer = reproduction_rate;
            } else {
              world->swap(x, y - 1, x, y);
            }
            return;
          } else if (selected->type == PREY_FISH) {
            neighbors += 1;
          }
        }
        break;
      case MoveDirection::LEFT:
        if (x > 0) {
          Object* selected = world->getObjectAt(x - 1, y);
          if (selected == nullptr) {
            if (reproduction_timer == 0) {
              world->replace(new Prey(Prey::generateReproductionRate(),
                                      Prey::generateLifetime()),
                             x - 1, y);
              reproduction_timer = reproduction_rate;
            } else {
              world->swap(x - 1, y, x, y);
            }
            return;
          } else if (selected->type == PREY_FISH) {
            neighbors += 1;
          }
        }
        break;
      case MoveDirection::RIGHT:
        if (x < world->getWidth() - 1) {
          Object* selected = world->getObjectAt(x + 1, y);
          if (selected == nullptr) {
            if (reproduction_timer == 0) {
              world->replace(new Prey(Prey::generateReproductionRate(),
                                      Prey::generateLifetime()),
                             x + 1, y);
              reproduction_timer = reproduction_rate;
            } else {
              world->swap(x + 1, y, x, y);
            }
            return;
          } else if (selected->type == PREY_FISH) {
            neighbors += 1;
          }
        }
        break;
      default:
        break;
    }
    direction = (direction + 1) % 4;
  } while (end_direction != direction);
}

int Prey::generateReproductionRate() {
  return PREY_MIN_REPRODUCTION_RATE +
         std::rand() %
             (PREY_MAX_REPRODUCTION_RATE - PREY_MIN_REPRODUCTION_RATE);
}

int Prey::generateLifetime() {
  return PREY_MIN_LIFETIME +
         std::rand() % (PREY_MAX_LIFETIME - PREY_MIN_LIFETIME);
}
