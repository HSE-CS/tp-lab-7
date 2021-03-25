// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include <vector>

#include "cell.h"
#include "common.h"
#include "object.h"

class Ocean {
 private:
  Cell*** cells;
  std::list<Object*> pool;
  std::list<Object*> deathPool;
  std::list<Object*> birthPool;

  size_t counter_prey = 0;
  size_t counter_predator = 0;

  void declare(Object*, Cell*);

  void generateCells();
  void generateObjects();

  void destroyCells();
  void destroyObjects();

  void runDeath();
  void runBirth();
  void sleep();

 public:
  Ocean();
  ~Ocean();
  void print() const;
  void run();

  void getNeighbours(coord_t center, std::vector<Cell*>&);

  void addToDeathPool(Object*);
  void addToBirthPool(Object*);
};

#endif  // INCLUDE_OCEAN_H_
