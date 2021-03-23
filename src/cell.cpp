// Copyright 2021 Khoroshavina Ekaterina
#include "cell.h"

void Cell::init(Pair p, Ocean* oc) {
    this->crd = p;
    this->ocean = oc;
}

Object* Cell::getObject() const {
    if (obj) {
        return obj;
    } else {
        return nullptr;
    }
}

void Cell::setObject(Object* obj) {
    this->obj = obj;
}

void Cell::killMe() {
    if (obj) {
        delete obj;
        this->obj = nullptr;
    }
}

Ocean* Cell::getOcean() {
    return this->ocean;
}

Pair Cell::getCrd() {
    return this->crd;
}

Cell* Cell::makeNewCell() {
    return ocean->newCell(this->getCrd());
}
