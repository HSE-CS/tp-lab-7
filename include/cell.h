// Copyright 2021 Shirokov Alexander

#ifndef _CELL_H_
#define _CELL_H_

#include "../include/common.h"
#include "../include/object.h"
#include "../include/ocean.h"

class Ocean;

class Cell
{
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
  void init(Pair p, Ocean* oc);
  Object* getObject() const;
  void setObject(Object*);
  void killMe();
  Ocean* getOcean();
  Cell* findPlace();
  Cell* findPrey();
};
#endif
