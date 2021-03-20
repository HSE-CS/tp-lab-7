// Copyright 2021 VadMack

#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include "common.h"
#include "cell.h"
#include <list>

class Cell;
class Object;
enum class ObjType;
class Ocean {

 private:
  Cell **cells;
  std::list<Object *> stuff;
  std::list<Object *> blackList;
  int sizeN;
  int sizeM;

 public:
  Ocean(int sizeN, int sizeM, int numOfStones, int numOfPreys, int numOfPredators);
  ~Ocean() = default;
  void print() const;
  void addObjects(ObjType type, int number);
  Cell *findCellAround(Pair coord);
  void run();

  void addObject(Object *);
  void removeObject(Object *);

  void addToBlackList(Object *obj);
  void thinTheRanks();
};

#endif  // INCLUDE_OCEAN_H_
