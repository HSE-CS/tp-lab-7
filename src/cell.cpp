//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#include "cell.h"

void Cell::init(Pair p, Ocean* oc) {
  this->crd = p;
  this->ocean = oc;
}

Pair Cell::getCrd() {
  return crd;
}

Object* Cell::getObject() {
  return this->obj;
}

Ocean* Cell::getOcean() {
  return ocean;
}

void Cell::setObject(Object* newObj) {
  this->obj = newObj;
}

bool Cell::isEmpty() const {
  if (this->obj == nullptr)
      return true;
  else
      return false;
}
