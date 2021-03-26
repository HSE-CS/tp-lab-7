// Copyright 2020 S. BOR
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "common.h"

class Cell;
class Ocean;
class Prey;
class Predator;

class Object {
 protected:
  Cell *currentCell;
 public:
  virtual bool isPrey() {return false;}
  void setCell(Cell *cell) {currentCell = cell;}
  virtual void nextTurn() = 0;
  virtual void printSymb() = 0;
};

class Cell {
 private:
  Object *obj;
  Coords coords;
  Ocean *ocean;
 public:
  Cell(Coords coords, Ocean *ocean);
  void setObject(Object *obj);
  Object *getObject();
  friend Ocean;
  friend Prey;
  friend Predator;
};

#endif  // INCLUDE_CELL_H_

