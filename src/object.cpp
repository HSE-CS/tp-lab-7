//// Copyright 2021 Ozhiganova Polina
#include "object.h"

Object::Object(ObjType type, Cell *cl) {
  this->ot = type;
  this->cell = cl;
}

Object::~Object() {
  this->cell = nullptr;
}

void Object::live() {
}

void Object::setCell(Cell *cl) {
  this->cell = cl;
}

ObjType Object::getObjType() {
  return this->ot;
}

void Object::setObjType(ObjType obj_type) {
  this->ot = obj_type;
}
