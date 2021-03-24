// Copyright 2021 Igumnova Natasha
#include <fstream>
#include <string>
#include <cmath>
#include "../include/object.h"
#include "../include/cell.h"
#include "../include/ocean.h"

void Object::setCell(Cell* cell_) {
    cell = cell_;
}
void Object::move() {
    return;
}
void Object::die() {
    this->dead = true;
}
Object::~Object() {
    cell->setObject(nullptr);
}

ObjType Object::getType() {
    return type;
}
