// Copyright 2021 Ilya Urtyukov
#include "cell.h"

Cell::Cell(Pair p, Ocean* oc) {
    coord = p;
    obj = nullptr;
    ocean = oc;
    isempty = true;
}

void Cell::init(Pair p, Ocean* oc) {
    coord = p;
    ocean = oc;
}

Object* Cell::getObject() {
    return obj;
}

void Cell::setObject(Object* a) {
    obj = a;
    if (a)
      isempty = false;
    else
      isempty = true;
}

bool Cell::isEmpty() {
    return isempty;
}

void Cell::killMe() {
    isempty = true;
    delete obj;
}
