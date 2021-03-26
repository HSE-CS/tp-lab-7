// Copyright 2021 Nikolaev Ivan

#include <iostream>
#include "object.h"

Object::Object(Cell* cell) {
    this->cell = cell;
}

Object::~Object() {
    this->cell = nullptr;
}

Cell* Object::getCell() {
    return cell;
}

void Object::setCell(Cell* cell) {
    this->cell = cell;
}

/*
char Object::getSymbol() {
    return symbol;
}*/
