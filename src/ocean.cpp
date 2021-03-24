// Copyright 2021 Egor Trukhin
#include "ocean.h"

#include <chrono>
#include <iostream>

#include "predator.h"
#include "prey.h"
#include "stone.h"

Ocean::Ocean() {
  generateCells();
  generateObjects();
}

Ocean::~Ocean() {
  destroyCells();
  destroyObjects();
}

//=============================================================
// Cell

void Ocean::generateCells() {
  cells = new Cell**[OCEAN_SIZE_HEIGHT];
  for (size_t y = 0; y < OCEAN_SIZE_HEIGHT; ++y) {
    cells[y] = new Cell*[OCEAN_SIZE_WIDTH];
    for (size_t x = 0; x < OCEAN_SIZE_WIDTH; ++x)
      cells[y][x] = new Cell({x, y}, this);
  }
}

void Ocean::destroyCells() {
  for (size_t y = 0; y < OCEAN_SIZE_HEIGHT; ++y) {
    for (size_t x = 0; x < OCEAN_SIZE_WIDTH; ++x) {
      delete cells[y][x];
    }
    delete[] cells[y];
  }
  delete[] cells;
}

//=============================================================
// Object

void Ocean::generateObjects() {
  std::random_device rd;
  std::mt19937 gen(rd());

  pool.clear();
  for (size_t i = 0; i < OCEAN_SIZE_HEIGHT; ++i) {
    for (size_t j = 0; j < OCEAN_SIZE_WIDTH; ++j) {
      uint32_t rand = gen();
      if (rand % 100 == 0) {
        declare(new Stone(), cells[i][j]);
        continue;
      } else if (rand % 33 == 0) {
        declare(new Predator(), cells[i][j]);
        ++counter_predator;
        continue;
      } else if (rand % 16 == 0) {
        declare(new Prey(), cells[i][j]);
        ++counter_prey;
        continue;
      }
    }
  }
}

void Ocean::destroyObjects() {
  while (pool.size() != 0) {
    Object* obj = pool.back();
    pool.pop_back();
    delete obj;
  }
}

//=============================================================

void Ocean::getNeighbours(coord_t center, std::vector<Cell*>& arr) {
  arr.clear();
  for (int8_t dy = -1; dy < 2; ++dy) {
    for (int8_t dx = -1; dx < 2; ++dx) {
      if (dy == 0 && dx == 0) continue;
      uint32_t pos_y = OCEAN_SIZE_HEIGHT + (center.y + dy);
      uint32_t pos_x = OCEAN_SIZE_WIDTH + (center.x + dx);
      arr.push_back(cells[pos_y % OCEAN_SIZE_HEIGHT][pos_x % OCEAN_SIZE_WIDTH]);
    }
  }
}

void Ocean::declare(Object* obj, Cell* cell) {
  pool.push_back(obj);
  obj->setCell(cell);
  cell->setObject(obj);
}

void Ocean::addToDeathPool(Object* obj) { deathPool.push_back(obj); }
void Ocean::addToBirthPool(Object* obj) { birthPool.push_back(obj); }

void Ocean::runDeath() {
  while (deathPool.size() != 0) {
    Object* obj = deathPool.back();

    size_t count = pool.size();
    pool.remove(obj);
    size_t new_count = pool.size();
    if (count != new_count) {
      object_t type = obj->getType();
      if (type == PREY)
        --counter_prey;
      else if (type == PREDATOR)
        --counter_predator;
    }

    birthPool.remove(obj);
    deathPool.pop_back();
    delete obj;
  }
}

void Ocean::runBirth() {
  while (birthPool.size() != 0) {
    Object* obj = birthPool.back();

    pool.push_back(obj);
    object_t type = obj->getType();
    if (type == PREY)
      ++counter_prey;
    else if (type == PREDATOR)
      ++counter_predator;

    birthPool.pop_back();
  }
}

void Ocean::sleep() {
  auto time = std::chrono::high_resolution_clock::now();
  float dTime = 0;
  while (dTime < OUTPUT_CYCLE_SLEEP) {
    auto curTime = std::chrono::high_resolution_clock::now();
    dTime = std::chrono::duration<double, std::milli>(curTime - time).count();
  }
}

//=============================================================

void Ocean::print() const {
#ifdef _WIN32
  // system("clear");  // for mingw terminal
  system("cls");  // for powershell/cmd
#elif defined(__linux__) || (defined(__APPLE__) && defined(__MACH__))
  // system("clear");
  std::cout << "\033[2J\033[1;1H" << std::endl;
#endif

  for (size_t i = 0; i < OCEAN_SIZE_HEIGHT; ++i) {
    for (size_t j = 0; j < OCEAN_SIZE_WIDTH; ++j) {
      Object* obj = cells[i][j]->getObject();
      if (obj == nullptr)
        std::cout << " ";
      else if (obj->getType() == STONE)
        std::cout << OUTPUT_SIGN_STONE;
      else if (obj->getType() == PREY)
        std::cout << OUTPUT_SIGN_PREY;
      else if (obj->getType() == PREDATOR)
        std::cout << OUTPUT_SIGN_PREDATOR;
    }
    std::cout << std::endl;
  }
}

void Ocean::run() {
  for (size_t iter = 1; iter <= OUTPUT_CYCLE_COUNT; ++iter) {
    print();
    std::cout << std::endl << "Iteration #" << iter << std::endl;
    std::cout << "Prey: " << counter_prey << std::endl;
    std::cout << "Predator: " << counter_predator << std::endl;
    if (counter_prey == 0 || counter_predator == 0) break;

    runDeath();
    runBirth();
    for (auto obj : pool) {
      obj->live();
    }

    sleep();
  }
}
