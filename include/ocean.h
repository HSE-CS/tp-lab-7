// Copyright 2021 Galex

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/object.h"

class Cell;
class Object;

class Ocean {
  friend  Cell;
 private:
  Cell* cells[ROWS][COLUMNS];
  std::list<Object *> stuff;
  int numOfPreys = 0;
  int numOfStones = 0;
  int numOfPredators = 0;
 public:
  Ocean();
  void print() const;
  void addObject(Object* o);
  void removeObject(Object* o);
  void run();
};

#endif  // INCLUDE_OCEAN_H_
