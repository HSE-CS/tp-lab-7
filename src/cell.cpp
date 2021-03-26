// Copyright 2021 Stolbov Yaroslav

#include "../include/cell.h"
#include "../include/ocean.h"


void Cell::initialize(Pair coordinates, Ocean* ocean) {
    this->ocean = ocean;
    this->coordinates = coordinates;
}

Cell* Cell::moveToCell() {
    return ocean->transferObject(coordinates);
}

Ocean* Cell::getOcean() {
    return this->ocean;
}

Object* Cell::getObject() const {
    if (object) {
        return object;
    } else {
        return nullptr;
    }
}

void Cell::setObject(Object* object) {
    this->object = object;
}

void Cell::killMe() {
    if (object) {
        delete object;
        this->object = nullptr;
    }
}

