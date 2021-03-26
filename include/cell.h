// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "../include/common.h"
#include "../include/object.h"

class Ocean;

class Cell {
  friend Ocean;
 private:
  coords currentCds;
  Object* inhabitant;
  Ocean* ocean;
  bool empty;

 public:
  explicit Cell(coords newCds = { 0, 0 }, Ocean* oc = nullptr) :
    currentCds(newCds), inhabitant(nullptr), ocean(oc), empty(true) {};
  void init(coords newCds, Ocean* ocean);
  Object* getObject() const;
  void setObject(Object* newInhabitant);
  void freeMe();
  coords getCoords();
  Ocean* getOcean() const;
  bool isEmpty();
};

#endif  // INCLUDE_CELL_H_
