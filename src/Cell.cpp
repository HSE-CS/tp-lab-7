//  Copyright 2021 Kartseva Masha
#include "Cell.h"
void Cell::init(Pair p, Ocean* oc) {
    crd = p;
    ocean = oc;
}
Object* Cell::getObject() const {
    if (obj)
        return obj;
    else
        return nullptr;
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
void Cell::Moving() {
    obj->setCell(nullptr);
    obj = nullptr;
}
Pair Cell::Cord() {
    return crd;
}
Ocean* Cell::getOcean() {
    return ocean;
}
Cell* Cell::RADAR() {
    return ocean->Radar(crd);
}
Cell* Cell::FREE() {
    return ocean->Step(crd);
}
