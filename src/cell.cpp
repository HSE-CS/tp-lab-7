// Copyright 2021 valvarl

#include "cell.h"
#include "ocean.h"

void Cell::init(Pair p, Ocean *oc) {
    crd = p;
    ocean = oc;
}

Ocean *Cell::getOcean() const {
    return ocean;
}

Object *Cell::getObject() const {
    return obj;
}

void Cell::setObject(Object *_obj) {
    obj = _obj;
}

const Pair &Cell::getCrd() const {
    return crd;
}

void Cell::killMe() {
    Cell c{crd, ocean};
    ocean->getCells()[crd.x][crd.y] = c;
}
