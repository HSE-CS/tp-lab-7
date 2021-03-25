// Copyright NikDemoShow 2021
#ifndef _CELL_H_
#define _CELL_H_

//#include "ocean.h"
#include "Object.h"
#include "common.h"
#include <random>

class Ocean;

class Cell {
 private:
  Pair crd;
  Object* obj;
  Ocean* ocean;

 public:
  explicit Cell(Pair p = {0, 0}, Ocean* oc = nullptr, Object* newObj = nullptr)
      : crd(p), obj(newObj), ocean(oc) {}
  Object* getObject() const;
  void setObject(Object*);
  ObjType getObjectType()const;
  void addObject(const ObjType type, Cell* newCell);
  Cell* getFreeNeighbour(const bool hugry = false);
  friend Ocean;
};
#endif
