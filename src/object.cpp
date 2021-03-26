// Copyright 2021 Stifeev Nikita

#include "../include/object.h"

Object::Object(Cell* cell, char sign) : cell(cell), sign(sign) {};

Object::~Object() {};

void Object::setCell(Cell* cell) {
    this->cell = cell;
}

char Object::getSign() {
    return sign;
}

Cell* Object::getCell() {
    return cell;
}
