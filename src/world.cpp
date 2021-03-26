#include "world.h"

#include <cstdlib>
#include <iostream>
#include <vector>

#include "predator.h"
#include "prey.h"
#include "stone.h"

World::World(int width, int height, int seed) : width(width), height(height) {
  objects.reserve(width * height);
  const int EMPTY = 20;
  const int STONE = 5;
  const int PREY = 3;
  const int PREDATOR = 1;
  std::srand(seed);
  for (int i = 0; i < width * height; ++i) {
    int cell_type = std::rand() % (EMPTY + STONE + PREY + PREDATOR);
    Object* o;
    if (cell_type < EMPTY) {
      o = nullptr;
    } else if (cell_type < EMPTY + STONE) {
      o = new Stone;
    } else if (cell_type < EMPTY + STONE + PREY) {
      o = new Prey;
    } else {
      o = new Predator;
    }
    objects.emplace_back(o);
  }
}

World::~World() {
  for (Object* o : objects) {
    delete o;
  }
}

void World::replace(Object* object, int x, int y) {
  delete objects[width * y + x];
  objects[width * y + x] = object;
}

int World::getWidth() const { return width; }

int World::getHeight() const { return height; }

bool World::update() {
  std::vector<std::pair<Object*, std::pair<int, int>>> prey;
  std::vector<std::pair<Object*, std::pair<int, int>>> predators;
  for (size_t i = 0; i < objects.size(); ++i) {
    if (objects[i] == nullptr) continue;
    switch (objects[i]->type) {
      case PREY_FISH:
        prey.emplace_back(objects[i], std::make_pair(i % width, i / width));
        break;
      case PREDATOR_FISH:
        predators.emplace_back(objects[i],
                               std::make_pair(i % width, i / width));
        break;
      case STONE:
        break;
    }
  }
  std::cout << "\033[2K"
            << "prey: " << prey.size() << "\n"
            << "\033[2K"
            << "predators: " << predators.size();
  if (prey.empty() || predators.empty()) {
    return true;
  }
  for (auto& p : prey) {
    p.first->update(*this, p.second.first, p.second.second);
  }
  for (auto& p : predators) {
    p.first->update(*this, p.second.first, p.second.second);
  }
  return false;
}

Object* World::getObjectAt(int x, int y) const {
  return objects[y * width + x];
}

void World::printWorld() const {
  for (int i = 0; i < width * height; ++i) {
    if (i % width == 0) std::cout << "\n";
    if (objects[i] == nullptr) {
      std::cout << "\033[37m"
                << "."
                << "\033[0m";
    } else if (objects[i]->type == PREY_FISH) {
      std::cout << "\033[94m"
                << "<"
                << "\033[0m";
    } else if (objects[i]->type == PREDATOR_FISH) {
      if (dynamic_cast<Predator*>(objects[i])->isSatiated()) {
        std::cout << "\033[33m"
                  << ">"
                  << "\033[0m";
      } else {
        std::cout << "\033[31m"
                  << ">"
                  << "\033[0m";
      }
    } else {
      std::cout << "\033[37m"
                << "#"
                << "\033[0m";
    }
  }
  std::cout << "\n";
}

void World::swap(int a_x, int a_y, int b_x, int b_y) {
  Object* tmp = objects[width * a_y + a_x];
  objects[width * a_y + a_x] = objects[width * b_y + b_x];
  objects[width * b_y + b_x] = tmp;
}
