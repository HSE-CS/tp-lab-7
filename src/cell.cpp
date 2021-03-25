// Copyright 2021 MalininDmitry

#include "cell.h"
#include "ocean.h"

void Cell::init(Pair p, Ocean* oc) {
    crd.x = p.x;
    crd.y = p.y;
    ocean = oc;
}

Object* Cell::getObject() const {
    return this->obj;
}

void Cell::setObject(Object * object) {
    obj = object;
}

void Cell::killMe() {
    this->obj = nullptr;

}

Pair Cell::getCrd() {
    return this->crd;
}

Ocean * Cell::getOcean() {
    return ocean;
}
