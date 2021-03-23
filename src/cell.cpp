// Copyright 2021 Ilya Urtyukov
#include "cell.h"


Cell::Cell() {
  crd(0, 0);
  object = nullptr;
  ocean = nullptr;
  isEmpty_ = true; 
}

void Cell::init(Pair crd, Ocean* ocean) {
  this->crd = crd;
  this->ocean = ocean;
}

Object* Cell::getObject() const {
  return object;
}

void Cell::setObject(Object* object) {
  this->object = object;
}

void Cell::killMe() {
  delete object;
}

Pair Cell::getCrd() const {
  return crd;
}

Ocean* Cell::getOcean() const {
  return ocean;
}

bool Cell::isEmpty() const {
  return isEmpty_;
}

void Cell::setIsEmpty(bool value) {
  isEmpty_ = value;
}
