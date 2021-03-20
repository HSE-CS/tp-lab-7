//// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "common.h"
#include "object.h"

class Ocean;

class Cell {
  friend Ocean;

 public:
  explicit Cell(Pair p = {0, 0}, Ocean *oc = nullptr) :
      crd(p),
      obj(nullptr),
      ocean(oc) {}
  void init(Pair p, Ocean *oc);
  [[nodiscard]] Object *getObject() const;
  [[nodiscard]] Ocean *getOcean() const;
  void setObject(Object *object);
  Cell *findPlace();
  bool checkPrey(Cell *cellToCheck) const;
  [[nodiscard]] Cell *goHunt() const;
  void killMe();

 private:
  Pair crd;
  Object *obj;
  Ocean *ocean;
};

#endif  //  INCLUDE_CELL_H_
