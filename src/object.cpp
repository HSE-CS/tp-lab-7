// Copyright Mushka Nikita 2021

#include <object.h>



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


void Object::setSymbol(char symbol) {
    this->symbol = symbol;
}

char Object::getSymbol() const {
    return this->symbol;
}

void Object::die() {
    this->cell = nullptr;
}
