// Copyright 2021 Elise
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>

#include "cell.h"
#include "common.h"
#include "predator.h"
#include "prey.h"
#include "stone.h"
#include "object.h"

class Ocean {
 private:
  Cell** cells;
  std::list<Object*> stuff;
  std::list<Object*> l_d;
  unsigned int X, Y, number;

 public:
  Ocean(int X, int Y, int number);
  ~Ocean();
  void print() const;
  void addObjects(int number);
  void run();

  Cell* coordinates(Pair coordinate);
  void addObject(Object* object_new);
  void AddListOfTheDead(Object* object_new);
  Cell* lets_go_eat(Pair coordinate);
};

#endif  // INCLUDE_OCEAN_H
