// Copyright 2021 mkhorosh

#include "../include/cell.h"

void Cell::init(Pair p, Ocean *oc) {
  this->crd = p;
  this->ocean = oc;
}

Object *Cell::getObject() const {
  return obj;
}

void Cell::setObject(Object *o) {
  this->obj = o;
}

void Cell::killMe() {
  obj = nullptr;
}
Pair Cell::getPair() {
  return this->crd;
}
Ocean *Cell::getOcean() {
  return this->ocean;
}
Cell *Cell::makeCell() {
  return ocean->findCell(this->getPair());
}

