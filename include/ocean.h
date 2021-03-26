// Copyright 2021 by me
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <vector>
#include <iostream>
#include <chrono>
#include <thread>


#include "cell.h"
#include "common.h"
#include "stone.h"
#include "prey.h"
#include "predator.h"

class Cell;
class Object;
class Stone;
class Prey;

class Ocean {
 private:
  Cell **cells;
  std::vector<Object *> stuff;
  size_t preyLife;
  size_t preyCoolDawn;
  size_t predatorLife;
  size_t predatorCoolDawn;
  size_t predatorHunger;

 public:
  explicit Ocean(size_t preyLife_ = 14, size_t preyCoolDawn_ = 3,
                 size_t predatorLife_ = 7, size_t predatorCoolDawn_ = 4,
                 size_t predatorHunger_ = 5);
  ~Ocean();
  void print() const;
  void addObjects(size_t number, ObjType type);
  void removeObj(Object *obj);
  void pushObject(Object *obj);
  void run();
  bool check();
  std::vector<Cell *> emptyCells(Pair point);
  std::vector<Cell *> preyCells(Pair point);
};
#endif  // INCLUDE_OCEAN_H_
