// Copyright 2021 Ryzhova
#include "../include/cell.h"

void Cell::init(Pair p, Ocean* oc) {
  crd = p;
  ocean = oc;
}

Cell::~Cell() {
  delete obj;
  ocean = nullptr;
}

Object* Cell::getObject() const {
  return obj;
}

Ocean* Cell::getOcean() const {
  return ocean;
}

Pair Cell::getCrd() {
  return crd;
}

void Cell::setObject(Object* obj) {
  this->obj = obj;
}

bool Cell::isEmpty() {
  return obj == nullptr;
}

void Cell::killMe() {
  delete obj;
  obj = nullptr;
}
