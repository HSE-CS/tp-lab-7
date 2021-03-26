// Copyright 2021 mkhorosh

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "common.h"
#include "cell.h"
#include "object.h"
#include "prey.h"
#include "predator.h"
#include "stone.h"
#include <vector>
#include <list>

class Ocean {
 private:
  std::vector<std::vector<Cell>> cells;
  std::list<Object *> stuff;

 public:
  Ocean(size_t x_size = M, size_t y_size = N);
  ~Ocean();
  void print() const;
  void push(Object *o);
  void addObjects(int stones = ST, int preys = P, int predators = PP);
  void run();
  Cell *findCell(Pair crd);
};

#endif  // INCLUDE_OCEAN_H_
