
// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_
#include <list>
#include "common.h"
#include "cell.h"
#include "predator.h"
#include "stone.h"
#include "prey.h"

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




