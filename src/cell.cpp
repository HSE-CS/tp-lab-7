// Copyright 2021 Sozinov Kirill
#include "../include/cell.h"

void Cell::init(Pair p, Ocean* oc) {
    this->crd = p;
    this->ocean = oc;
}

Object* Cell::getObject() const {
    return obj;
}

void Cell::setObject(Object* object_) {
    this->obj = object_;
}

void Cell::killMe() {
    this->ocean->AddListOfTheDead(obj);
    this->obj = nullptr;
}

void Cell::setOcean(Ocean* ocean_) {
    this->ocean = ocean_;
}

Ocean* Cell::getOcean() {
    return ocean;
}

Cell* Cell::seachEmptyPlace() {
    return ocean->seachEmptyPlace({ crd.x, crd.y });
}

Cell* Cell::hunt() {
    return ocean->hunt({ crd.x, crd.y });
}
