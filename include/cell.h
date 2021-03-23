// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "../include/object.h"

class Ocean;

class Cell {
friend Ocean;
 private:
  Pair crd;
  Object* obj;
  Ocean* ocean;
 public:
  explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
  crd(p), obj(nullptr), ocean(oc) {}
  void init(Pair p, Ocean* oc);
  Object* getObject() const;
  void setObject(Object*);
  void killMe();
  Cell* moveToCell();
  Ocean* getOcean();
};

#endif  // INCLUDE_CELL_H_





