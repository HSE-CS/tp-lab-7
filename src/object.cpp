// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 20.03.2021.
//
#include "../include/object.h"

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

void Object::setObjType(ObjType objTypeValue) {
  this->ot = objTypeValue;
}
