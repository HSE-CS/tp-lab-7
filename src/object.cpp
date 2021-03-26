// Copyright 2020 Osmanov Islam

#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Object::Object(ObjType curType, Cell *cell1) {
    this->objType = curType;
    this->cell = cell1;
    this->isAlive = false;
}

void Object::setCell(Cell* c) {
    cell = c;
}

Object::~Object() {
    cell->setObject(nullptr);
}

void Object::move() {
    return;
}

void Object::alive() {
    this->isAlive = true;
}

ObjType Object::getType() {
    return objType;
}


