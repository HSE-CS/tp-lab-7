// Copyright 2021 Dmitry Vargin
#include "../include/cell.h"

Cell::Cell(std::pair<int, int> p, Ocean *oc) {
    this->crd = p;
    this->ocean = oc;
}

Object * Cell::getObject() const {
    return this->object;
}

void Cell::setObject(Object *obj) {
    this->object = obj;
}

Ocean * Cell::getOcean() {
    return this->ocean;
}
