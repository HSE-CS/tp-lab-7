// Copyright 2021 BekusovMikhail

#include "../include/object.h"

Object::Object(Cell *cell) {
    this->cell = cell;
}

Object::~Object() {
    this->cell = nullptr;
}

void Object::setCell(Cell *cell) {
    this->cell = cell;
}

Cell *Object::getCell() {
    return this->cell;
}

char Object::getType() {
    return this->type;
}

void Object::setType(char type) {
    this->type = type;
}

