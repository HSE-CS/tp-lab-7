// Copyright [2020] <Olesya Nikolaeva>

#include "cell.h"

void Cell::init(Pair p, Ocean* oc) {
    crd = p;
    obj = nullptr;
    ocean = oc;
}

Object* Cell::getObject() const {
    return obj;
}

void Cell::setObject(Object* new_obj) {
    obj = new_obj;
}

