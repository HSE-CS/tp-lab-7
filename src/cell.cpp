// Copyright 2021 Lab_7 TiNa
#include "cell.h"

void Cell::init(Pair p, Ocean* oc) {
  crd = p;
  ocean = oc;
}

Object* Cell::getObject() const { return obj; }

void Cell::setObject(Object* objectIn) { obj = objectIn; }

Ocean* Cell::getOcean() const { return ocean; }

void Cell::killMe() {
  if (obj) {
    obj = nullptr;
  }
}

bool Cell::isEmpty() { return obj == nullptr; }

Cell* Cell::eat() { return ocean->eat({crd.x, crd.y}); }

Cell* Cell::find() { return ocean->find({crd.x, crd.y}); }
