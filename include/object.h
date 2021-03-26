// Copyright NikDemoShow 2021
#ifndef INCLUDE_OBJECT_H_
#define INCLUDE_OBJECT_H_

#include "common.h"

class Cell;
class Object {
 protected:
  Cell *cell;
  ObjType type;

 public:
  virtual void live() = 0;
  void set(Cell *);
  Cell *getCell();
  friend Cell;
};
#endif  // INCLUDE_OBJECT_H_
