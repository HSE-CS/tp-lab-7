// Copyright 2021 Galex

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "../include/common.h"
#include "../include/object.h"
#include "../include/ocean.h"

class Object;
class Ocean;

class Cell{
 private:
  Ocean* ocean;
  Object* object;
  Pair coord;
  Cell* checkNeighbour(int neighbour);
 public:
  Ocean* getOcean();
  explicit Cell(Pair p, Ocean* o);
  Object* getObject();
  void setObject(Object* obj);
  bool isFree();
  Cell* getRandNeighbourCell();
  Cell* getNeighbourCell();
  Cell* getRandPreyNeighbourCell();
  void kill();
};
#endif  // INCLUDE_CELL_H_
