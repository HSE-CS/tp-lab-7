// Copyright TimurZaytsev 2021
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include <random>

#include "../include/common.h"
#include "../include/object.h"

class Ocean;

class Cell {
 private:
  Pair crd;
  Object* obj;
  Ocean* ocean;

 public:
  explicit Cell(Pair p = {0, 0}, Ocean* oc = nullptr,
                Object* newObj = nullptr)
      : crd(p), obj(newObj), ocean(oc) {}
  Object* getObj() const;
  void setObj(Object*);
  ObjType getObjType() const;
  void addObj(const ObjType type, Cell* newCell);
  Cell* getNeighbour(const bool hugry = false);
  friend Ocean;
};
#endif  // INCLUDE_CELL_H_
