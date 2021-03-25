// Copyright 2021 Dumarevskaya
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "common.h"
#include "Object.h"

class Ocean;
class Cell {
  friend Ocean;
 private:
  Pair crd;
  Object* obj;
  Ocean* ocean;

 public:
  explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
    crd(p),
    obj(nullptr),
    ocean(oc) {}
  ~Cell() {}
  void init(Pair p, Ocean* oc);
  Object* getObject() const;
  void setObject(Object*);
  Cell* findEmptyAround();
  Cell* findPreyAround();
  Ocean* getOcean();
  void killMe();
};

#endif  // INCLUDE_CELL_H_
