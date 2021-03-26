#ifndef _INCLUDE_OCEAN_H_
#define _INCLUDE_OCEAN_H_

#include <vector>
#include <iostream>

#include "Cell.h"
#include "common.h"
#include "stone.h"
#include "prey.h"

class Cell;
class Object;
class Stone;
class Prey;

class Ocean {
 private:
  Cell **cells;
  std::vector<Object *> stuff;
  size_t preyLife;
  size_t preyCoolDawn;
  size_t predatorLife;

 public:
  Ocean();
  ~Ocean();
  void print() const;
  void addObjects(size_t number, ObjType type);
  void pushObject(Object* obj);
  void run();
  bool check();
  std::vector<Cell *> emptyCells(Pair point);
};
#endif  // _INCLUDE_OCEAN_H_