// Copyright 2021 Artem Danyaev
#pragma once

#include <stdlib.h>
#include <iostream>
#include <list>
#include "../include/cell.h"
#include "../include/object.h"
#include "../include/common.h"

class Cell;
class Object;
class Ocean {
 private:
  Cell** cells;
  std::list<Object*> stuff;
  std::list<Object*> stuffToBeKilled;
  int countPredators() const;
  int countPreys() const;

 public:
  Ocean();
  void print() const;
  void addObjects();
  void addObject(Object* o);
  void deleteObject(Object* o);
  void run();
  Cell* getCell(Pair crd);
};
