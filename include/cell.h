// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "../include/common.h"
#include "../include/object.h"
#include "../include/ocean.h"

class Ocean;

class Cell {
  friend Ocean;

 private:
  Pair crd;
  Object *obj;
  Ocean *ocean;

 public:
  explicit Cell(Pair _p = {narrow_cast<int>(0), narrow_cast<int>(0)},
                Ocean *_ocean = nullptr)
      : crd(_p), obj(nullptr), ocean(_ocean) {}
  Object *getObject() const;
  void setObject(Object *);
  void killMe();
  Ocean *getOcean() const;
};

#endif  // INCLUDE_CELL_H_
