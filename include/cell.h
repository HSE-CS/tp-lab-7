// Copyright 2021 Egor Trukhin
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "common.h"

class Ocean;
class Object;

class Cell {
 private:
  coord_t position;
  Ocean* ocean;
  Object* object;

 public:
  explicit Cell(coord_t position = {0, 0}, Ocean* = nullptr, Object* = nullptr);

  void setObject(Object*);

  coord_t getPostion() const;
  Object* getObject() const;

  Cell* findNeighbourCell(object_t = NONE);

  void declareBirth(Object*);
  void declareDeath();
};

#endif  // INCLUDE_CELL_H_
