// Copyright 2021 Kriss Egorova


#include "object.h"
#include "cell.h"
#include "ocean.h"

Object::~Object() {
    cell->setObject(nullptr);
}

void Object::move() {
    return;
}

void Object::setCell(Cell* newCell) {
    this->cell = newCell;
}

ObjType Object::getObjType() {
    return this->objType;
}

void Object::live() {
    return;
}

bool Object::isDead() {
    return objType == ObjType::DEAD;
}