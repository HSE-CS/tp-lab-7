// Copyright 2021 Schenikova
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include <vector>
#include <iostream>
#include <unistd.h>

#include "./common.h"
#include "./cell.h"

class Cell;
class Object;
class Prey;
class Predator;

class Ocean {
 private:
  Cell **cells;
  std::list<Object*> stuff;
  int countPrey = 0;
  int countPredator = 0;
  std::list<Object*> delList;
 public:
  Ocean();
  ~Ocean();
  void print();
  void addObjects(std::vector<Object*> objects);
  void run();
  void delObj();
  void addToList(Object* obj);
  friend Prey;
  friend Predator;
};
#endif  // INCLUDE_OCEAN_H_
