// Copyright 2021 Lab_7 TiNa
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "object.h"
#include "common.h"
#include "ocean.h"

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
  Object* getObject() const;
  void setObject(Object* objectIn);
  Ocean* getOcean() const;
  void killMe();
  bool isEmpty();
  Cell* eat();
  Cell* find();
};

#endif  // INCLUDE_CELL_H_
