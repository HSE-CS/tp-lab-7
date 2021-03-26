// Copyright 2021 Andrey Bakurskii

#include "..\include\cell.h"

void Cell::initCell(Pair c, Ocean *oc) {
  this->coord = c;
  this->ocean = oc;
}

Pair Cell::getCoord() { return this->coord; }

Object *Cell::getObject() { return this->object; }

void Cell::setObj(Object *obj) {
  this->object = obj;
  if (obj == nullptr) {
    this->obj_type = ObjType::EMPTY;
    
    return;
  }
  this->obj_type = obj->getObjectType();
}

void Cell::deleteObj() { delete this->object; }
