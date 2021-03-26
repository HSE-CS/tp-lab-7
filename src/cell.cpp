// Copyright 2021 Egor Buzanov

#include "../include/cell.h"

Object *Cell::getObject() const { return obj; }

void Cell::setObject(Object *_obj) { obj = _obj; }

void Cell::killMe() {
  ocean->deleteObject(obj);
  obj = nullptr;
}

Ocean *Cell::getOcean() const { return ocean; }
