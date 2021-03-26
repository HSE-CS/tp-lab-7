// Copyright 2021 VladimirUspensky

#include "../include/cell.h"
#include "../include/ocean.h"

void Cell::init(Pair p, Ocean *o) {
    crd = p;
    ocean = o;
}

void Cell::killMe() {
    Cell c{crd, ocean};
    ocean->getCells()[crd.x_coord][crd.y_coord] = c;
}

void Cell::setObject(Object *object) {
    this->obj = object;
}

Ocean *Cell::getOcean() const {
    return this->ocean;
}

Object *Cell::getObject() const {
    return this->obj;
}

const Pair &Cell::getCrd() const {
    return this->crd;
}

