// Copyright NikDemoShow 2021
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include <random>
#include "object.h"
#include "common.h"

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
#endif  // INCLUDE_CELL_H_
