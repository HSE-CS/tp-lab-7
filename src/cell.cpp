// Copyright 2021 soda

#include "../include/cell.h"
#include "../include/ocean.h"

void Cell::setObject(Object* obj) {
    this->obj = obj;
}

void Cell::init(Pair p, Ocean* oc) {
    crd = p;
    ocean = oc;
}

Object* Cell::getObject() const {
    return this->obj;
}

Ocean* Cell::getOcean() {
    return this->ocean;
}

Pair Cell::getCord() {
    return this->crd;
}

void Cell::killMe(Object* fdel) {
    this->obj = nullptr;
}

void Cell::delObj() {
    this->obj = nullptr;
}
