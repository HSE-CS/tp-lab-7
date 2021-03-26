// Copyright 2021 mkhorosh

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <vector>
#include <list>
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/object.h"
#include "../include/prey.h"
#include "../include/predator.h"
#include "../include/stone.h"

class Ocean {
 private:
  std::vector<std::vector<Cell>> cells;
  std::list<Object *> stuff;

 public:
  explicit Ocean(int x_size = M, int y_size = N);
  ~Ocean();
  void print() const;
  void push(Object *o);
  void addObjects(int stones = ST, int preys = P, int predators = PP);
  void run();
  Cell *findCell(Pair crd);
};

#endif  // INCLUDE_OCEAN_H_
