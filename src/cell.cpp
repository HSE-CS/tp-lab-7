// Copyright [2020] <Olesya Nikolaeva>

#include "cell.h"
#include "ocean.h"

void Cell::init(Pair p, Ocean* oc) {
    crd = p;
    obj = nullptr;
    ocean = oc;
}

void Cell::changeStatus(bool arg) {
    isfree = arg;
    if (arg == true) {
        setObject(nullptr);
    }
}

Object* Cell::getObject() const {
    return obj;
}

void Cell::setObject(Object* new_obj) {
    obj = new_obj;
}

Pair Cell::returnLocation() {
    return crd;
}

bool Cell::returnCellfromOcean(Pair arg) {
    return ocean->returnCellStatus(arg);
}

Cell* Cell::returnCellPointer(Pair arg) {
    return ocean->returnCell(arg);
}
