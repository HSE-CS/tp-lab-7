// Copyright NikDemoShow 2021
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <vector>

#include "common.h"

class Object;
class Cell;

class Ocean {
 private:
  Cell **cells;
  std::vector<Object *> s;
  std::vector<Object *> tempOfStuff;

 public:
  Ocean();
  ~Ocean();
  void go();
  void addObj(const ObjType type, Cell *newCell);
  void addObj();
  void delObj();
  void print() const;
  Cell *getCell(const unsigned int x, const unsigned int y);
};
#endif  // INCLUDE_OCEAN_H_
