
// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_
#include <list>
#include "../include/common.h"
#include "../include/cell.h"
#include "../include/predator.h"
#include "../include/stone.h"
#include "../include/prey.h"

class Ocean {
 private:
  Cell** cells;
  std::list<Object*> stuff;
 public:
  Ocean();
  ~Ocean();

  void addObjects(unsigned int n, ObjType type);
  void run();
  void print() const;
  Cell* moveObj(Pair crd);
  void addObj(Object* obj);
};

#endif  // INCLUDE_OCEAN_H_




