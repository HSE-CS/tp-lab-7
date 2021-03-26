// Copyright 2020 Uskova

#include "Object.h"

Object::Object(Cell* c, ObjType objType) {
    this->cell = c;
    this->type = objType;
}

Object::~Object() {
  this->cell = nullptr;
  this->type = ObjType::EMPTY;
}

void Object::setCell(Cell* c) {
    this->cell = c;
}

void Object::setObjType(ObjType obType) {
    this->type = obType;
}

ObjType Object::getType() {
    return this->type;
}
