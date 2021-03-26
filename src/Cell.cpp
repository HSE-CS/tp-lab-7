// Copyright 2021 Vlad
#include "Cell.h"

void Cell::init(Pair p, Ocean* oc) {
    crd = p;
    ocean = oc;
}

Object* Cell::getObject() const {
    return obj;
}

void Cell::setObject(Object* object) {
    this->obj = object;
    if(ocean != nullptr)
        ocean->AddObject(object);
}

void Cell::killMe() {
    ocean->removeObject(obj);
    delete obj;
    obj = nullptr;
}

Ocean* Cell::getOcean() {
    return ocean;
}

int Cell::getX() {
    return crd.x;
}

int Cell::getY() {
    return crd.y;
}

void Cell::removeObj() {
    this->obj = nullptr;
}

void Cell::addObject(Object* obj) {
    this->obj = obj;
}
