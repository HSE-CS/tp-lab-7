// Copyright 2021 LongaBonga
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "common.h"
#include "object.h"
#include "ocean.h"

class Ocean;

class Cell {
  friend Ocean;

 private:
  Pair crd;
  Object *obj;
  Ocean *ocean;

 public:
  explicit Cell(Pair p = {0, 0}, Ocean *oc = nullptr)
      : crd(p), obj(nullptr), ocean(oc) {}
  void init(Pair p, Ocean *oc);
  Object *getObject() const;
  void setObject(Object *);
  void killMe();
  void Moving();
  Pair Cord();
  Ocean *getOcean();
  Cell *RADAR();
  Cell *FREE();
};
#endif  // INCLUDE_CELL_H_
