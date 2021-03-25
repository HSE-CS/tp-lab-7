// Copyright NikDemoShow 2021
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "common.h"

class Cell;
class Object {
 protected:
  Cell *cell;
  ObjType type;
 public:
  virtual void live() = 0;  // жизнь объекта
  void setCell(Cell *);
  Cell* getCell();
  friend Cell;
};
#endif
