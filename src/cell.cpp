// Copyright 2021 Nikolaev Ivan

#include <iostream>
#include "cell.h"
#include "ocean.h"

void Cell::init(Pair p, Ocean* oc) {
    crd = p;
    ocean = oc;
}

Ocean* Cell::getOcean() {
    return ocean;
}

Object* Cell::getObject() {
    return obj;
}

void Cell::setObject(Object* obj) {
    this->obj = obj;
}

char Cell::getSymbol() {
    return symbol;
}

Pair Cell::getCrd() {
    return crd;
}

void Cell::setCrd(Pair crd) {
    this->crd = crd;
}
