// Copyright 2020 S. BOR

#include "include/cell.h"

Cell::Cell(Coords coords, Ocean *ocean) {
  this->coords = coords;
  this->ocean = ocean;
  this->obj = nullptr;
}

void Cell::setObject(Object *obj) {
  this->obj = obj;
  if (obj != nullptr)
    obj->setCell(this);
}

Object *Cell::getObject() {
  return obj;
}
