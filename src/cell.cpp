// Copyright 2021 VadMack

#include "../include/cell.h"

Object *Cell::getObject() const {
  return obj;
}

void Cell::setObject(Object *obj) {
  this->obj = obj;
}

void Cell::killMe() {
  if (obj) {
    this->ocean->addToBlackList(obj);
    obj = nullptr;
  }
}

Cell *Cell::findCellAround() {
  return ocean->findCellAround({crd.x, crd.y});
}

Cell *Cell::findCellWithPrey() {
  return ocean->findCellWithPrey({crd.x, crd.y});
}

Ocean *Cell::GetOcean() const {
  return ocean;
}

void Cell::SetOcean(Ocean *ocean) {
  Cell::ocean = ocean;
}

void Cell::init(Pair p, Ocean *oc) {
  this->crd = p;
  this->ocean = oc;
}





