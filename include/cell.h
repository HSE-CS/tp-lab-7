// Copyright 2021 VadMack

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include <string>
#include "../include/common.h"
#include "../include/ocean.h"

#define RED "S"
#define GREY "#"
#define PINK "f"
#define BLUE "."

class Ocean;
class Object;
class Cell {
  friend Ocean;
 private:
  Pair crd;
  Object *obj;
  Ocean *ocean;

 public:
  explicit Cell(Pair p = {0, 0}, Ocean *oc = nullptr) :
      crd(p),
      obj(nullptr),
      ocean(oc) {
  }
  void init(Pair p, Ocean *oc);
  Object *getObject() const;
  void setObject(Object *);
  void killMe();

  Cell *findCellAround();

  Ocean *GetOcean() const;
  void SetOcean(Ocean *ocean);

  Cell *findCellWithPrey();
};

#endif  // INCLUDE_CELL_H_
