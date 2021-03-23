// Copyright by Egor Bodrov 2021

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "../include/common.h"
#include "../include/object.h"
#include "../include/ocean.h"

class Ocean;

class Cell {
  friend Ocean;

 private:
  pair loc;
  Object* obj{nullptr};
  Ocean* ocean;

 public:
  Cell() = default;

  explicit Cell(pair coords, Ocean* ocean);

  void init(pair coords, Ocean* ocean);

  Object* getObject() const;

  void setObject(Object* object);

  void killMe();

  Cell* findPlace();

  Cell* findPrey();

  Ocean* getOcean();
};


#endif  // INCLUDE_CELL_H_
