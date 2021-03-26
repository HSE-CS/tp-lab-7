// Copyright 2020 Uskova
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "Object.h"
#include "common.h"
#include "ocean.h"
#include <iostream>
#include <ctime>
#include <vector>

class Ocean;

class Cell {
  friend Ocean;
 private:
  Pair crd;
  Object* obj;
  Ocean* ocean;
 public:
  explicit Cell(Pair p = {0, 0}, Ocean* oc = nullptr)
      : crd(p), obj(nullptr), ocean(oc) {}
  void init(Pair p, Ocean* oc);
  Object* getObject();
  Pair getCrd();
  void setObject(Object*);
  Cell* freePlace();
  Cell* forHunting();
  Ocean* getOcean();
  //void killMe();
};

#endif  //  INCLUDE_CELL_H_
