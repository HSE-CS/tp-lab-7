// Copyright 2021 Lab_7 TiNa
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>

#include "cell.h"
#include "common.h"
#include "predator.h"
#include "prey.h"
#include "stone.h"

class Ocean {
 private:
  Cell **cells;
  std::list<Object *> stuff;
  int num_of_obj;

 public:
  Ocean();
  ~Ocean();
  void print() const;
  void addObjects(int num_of_obj);
  void addObjects(Object* objIn);
  void run();
  Cell *eat(Pair cor);
  Cell *find(Pair cor);
};

#endif  // INCLUDE_OCEAN_H_
