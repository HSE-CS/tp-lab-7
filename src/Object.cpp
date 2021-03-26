//  Copyright 2021 Kartseva Masha
#include "Object.h"
Object::Object(Cell* cell) {
    this->cell = cell;
}

void Object::setCell(Cell* cell) {
    this->cell = cell;
}

Cell* Object::getCell() {
    return cell;
}

unsigned int Object::getLive() {
    return lifetime;
}

void Object::setLive(int lifetime) {
    this->lifetime = lifetime;
}

bool Object::is_live() {
    return dead;
}

void Object::readytodie() {
    dead = true;
}

ObjType Object::getType() {
    return type;
}
