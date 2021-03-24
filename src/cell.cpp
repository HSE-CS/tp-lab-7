// Copyright 2021 Igumnova Natasha
#include "../include/cell.h"
#include <fstream>
#include <string>
#include <cmath>

void Cell::init(Pair p_, Ocean* oc_) {
    crd = p_;
    obj = nullptr;
    ocean = oc_;
}
Object* Cell::getObject() const {
    return obj;
}
void Cell::setObject(Object* obj_) {
    obj = obj_;
}
int Cell::getX() const {
    return crd.x;
}
int Cell::getY() const {
    return crd.y;
}
Ocean* Cell::getOcean() const {
    return ocean;
}
bool Cell::isEmpty() const {
    return this->obj == nullptr;
}
void Cell::killMe() {
    if (obj) {
        obj = nullptr;
    }
}
