// Copyright 2021 Igumnova Natasha
#include "object.h"
#include "cell.h"
#include "ocean.h"
#include <fstream>
#include <string>
#include <cmath>

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
