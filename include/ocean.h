// Copyright 2021 Shirokov Alexander

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <list>
#include "../include/common.h"
#include "../include/cell.h"

class Ocean {
 private:
  Cell** cells;
  std::list<Object*> stuff;
  std::list<Object*> killed;
  Pair size;

 public:
  Ocean(unsigned N, unsigned M, unsigned Predators, unsigned Preys,
    unsigned Stones, unsigned Corals);
  ~Ocean();
  void print() const;
  void addObjects(int num, ObjType type);
  void addObject(Object* obj);
  void run();
  void addToKilledList(Object* obj);
  void clearKilledList();
  Cell* findEmpty(Pair crd);
  Cell* findPrey(Pair crd);
};
#endif  // INCLUDE_OCEAN_H_
