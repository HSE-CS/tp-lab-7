// Copyright 2020 Osmanov Islam

#include <string>
#include <iostream>
#include <cmath>
#include <fstream>
#include "../include/cell.h"

Object* Cell::getObject() const {
    return this->obj;
}

Ocean* Cell::getOcean() const {
    return this->ocean;
}

Cell::Cell(Pair par, Ocean *ocean1) {
    this->crd = par;
    this->ocean = ocean1;
    this->obj = nullptr;
}

void Cell::init(Pair p_, Ocean* oc_) {
    this->crd = p_;
    this->obj = nullptr;
    this->ocean = oc_;
}

void Cell::setObject(Object* curObj) {
    this->obj = curObj;
}
