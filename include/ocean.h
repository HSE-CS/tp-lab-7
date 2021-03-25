// Copyright NikDemoShow 2021
#ifndef INCLUDE_OCEAN_H_
#define INCLUDE_OCEAN_H_

#include <vector>
#include "common.h"

//class Cell;
class Object;
class Cell;

class Ocean {
 private:
  Cell **cells;
  std::vector<Object *> stuff;
  std::vector<Object*> tempStuff;

 public:
  Ocean();
  ~Ocean();
  void run();
  void addObject(const ObjType type, Cell* newCell);
  void addObjects();
  void delObjects();
  void print() const;
  Cell *getCell(const unsigned int x, const unsigned int y);
};
#endif  // INCLUDE_OCEAN_H_
