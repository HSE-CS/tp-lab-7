// Copyright 2021 VadMack

#include "cell.h"

void Cell::init(Pair p, Ocean* oc){
  this->crd = p;
  this->ocean = oc;
}

Object *Cell::getObject() const {
  return obj;
}

void Cell::setObject(Object *obj) {
  this->obj = obj;
}

void Cell::killMe() {
  if (obj){
    delete obj;
    obj = nullptr;
  }
}

Cell *Cell::findCellAround() {
    return ocean->findCellAround({crd.x, crd.y});
}
Ocean *Cell::GetOcean() const {
  return ocean;
}
void Cell::SetOcean(Ocean *ocean) {
  Cell::ocean = ocean;
}





