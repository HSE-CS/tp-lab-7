//  Copyright 2021 Nikita Naumov

#include "../include/Object.h"
#include "../include/cell.h"

Object::Object(Cell *objToSet) {
    this->cell = objToSet;
}

Object::~Object() { this->cell = nullptr; }
void Object::setCell(Cell* objToSet) { this->cell = objToSet; }
ObjType Object::getType() {
    if (this == nullptr) {
        return ObjType::NONE;
    }
    return this->type;
}
Cell * Object::getCell() {
    return this->cell;
}
Pair Object::getPair() {
    return this->cell->getPair();
}