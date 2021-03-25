#include "predator.h"

#include <cstdlib>

void Predator::update(World* world, int x, int y) {
  energy -= 1;
  if (energy == 0) {
    world->replace(nullptr, x, y);
    return;
  }
  int direction = std::rand() % 4;
  int end_direction = direction;
  int phase = 0;
  bool done = false;
  do {
    switch (direction) {
      case MoveDirection::DOWN:
        if (y < world->getHeight() - 1) {
          Object* selected = world->getObjectAt(x, y + 1);
          if (phase == 0) {
            if (selected == nullptr) {
              if (satiated) {
                world->replace(new Predator(Predator::generateLifetime()), x,
                               y + 1);
                satiated = false;
                return;
              }
            } else if (selected->type == ObjectType::PREY_FISH && !satiated) {
              world->replace(nullptr, x, y + 1);
              satiated = true;
              return;
            }
          } else {
            if (selected == nullptr) {
              world->swap(x, y + 1, x, y);
              return;
            }
          }
        }
        break;
      case MoveDirection::UP:
        if (y > 0) {
          Object* selected = world->getObjectAt(x, y - 1);
          if (phase == 0) {
            if (selected == nullptr) {
              if (satiated) {
                world->replace(new Predator(Predator::generateLifetime()), x,
                               y - 1);
                satiated = false;
                return;
              }
            } else if (selected->type == ObjectType::PREY_FISH && !satiated) {
              world->replace(nullptr, x, y - 1);
              satiated = true;
              return;
            }
          } else {
            if (selected == nullptr) {
              world->swap(x, y - 1, x, y);
              return;
            }
          }
        }
        break;
      case MoveDirection::LEFT:
        if (x > 0) {
          Object* selected = world->getObjectAt(x - 1, y);
          if (phase == 0) {
            if (selected == nullptr) {
              if (satiated) {
                world->replace(new Predator(Predator::generateLifetime()),
                               x - 1, y);
                satiated = false;
                return;
              }
            } else if (selected->type == ObjectType::PREY_FISH && !satiated) {
              world->replace(nullptr, x - 1, y);
              satiated = true;
              return;
            }
          } else {
            if (selected == nullptr) {
              world->swap(x - 1, y, x, y);
              return;
            }
          }
        }
        break;
      case MoveDirection::RIGHT:
        if (x < world->getWidth() - 1) {
          Object* selected = world->getObjectAt(x + 1, y);
          if (phase == 0) {
            if (selected == nullptr) {
              if (satiated) {
                world->replace(new Predator(Predator::generateLifetime()),
                               x + 1, y);
                satiated = false;
                return;
              }
            } else if (selected->type == ObjectType::PREY_FISH && !satiated) {
              world->replace(nullptr, x + 1, y);
              satiated = true;
              return;
            }
          } else {
            if (selected == nullptr) {
              world->swap(x + 1, y, x, y);
              return;
            }
          }
        }
        break;
      default:
        break;
    }
    direction = (direction + 1) % 4;
    if (phase == 0 && end_direction == direction) {
      phase += 1;
    } else if (phase == 1 && end_direction == direction) {
      done = true;
    }
  } while (!done);
}

int Predator::generateLifetime() {
  return PREDATOR_MIN_LIFETIME +
         std::rand() % (PREDATOR_MAX_LIFETIME - PREDATOR_MIN_LIFETIME);
}
