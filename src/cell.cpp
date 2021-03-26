// Copyright 2021 Shirokov Alexander

#include "../include/cell.h"
#include "../include/object.h"

void Cell::init(Pair p, Ocean* oc) {
  this->crd = p;
  this->ocean = oc;
}

Object* Cell::getObject() const {
  return this->obj;
}

void Cell::setObject(Object* obj) {
  this->obj = obj;
}

void Cell::killMe() {
  if (this->obj != nullptr) {
    this->ocean->addToKilledList(this->obj);
    this->obj = nullptr;
  }
}

Ocean* Cell::getOcean() {
  return this->ocean;
}

Cell* Cell::findPlace() {
  return this->ocean->findEmpty(this->crd);
}

Cell* Cell::findPrey() {
  return this->ocean->findPrey(this->crd);
}
