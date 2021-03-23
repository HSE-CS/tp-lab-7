// Copyright by Egor Bodrov 2021

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "../include/common.h"
#include "../include/cell.h"

#include <list>

class Ocean {
 private:
  Cell** surface;
  std::list<Object*> stuff;
  std::list<Object*> killed;
  pair size;

 public:
  Ocean(unsigned N, unsigned M, unsigned PredNum, unsigned PreyNum, unsigned StoneNum);
  ~Ocean();

  void print() const;

  void addObjects(int num, ObjectType type);

  void run();

  void addObject(Object *obj);

  void addToKilledList(Object *obj);

  void clearKilledList();

  Cell *findPrey(pair coord);

  Cell *findEmpty(pair coord);
};




#endif  // INCLUDE_OCEAN_H_