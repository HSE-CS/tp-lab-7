// Copyright 2021 Kasyanov
#include "cell.h"

void Cell::init(std::pair<size_t, size_t> p, Ocean* oc) {
    crd = p;
    ocean = oc;
}

Object* Cell::getObject() const {
    return obj;
}

void Cell::setObject(Object * object) {
    obj = object;
}

void Cell::killMe() {
    obj = nullptr;
}

std::ostream& operator<<(std::ostream& out, const Cell& cell) {
    if (!cell.obj) {
        out << CORAL_N;
        return out;
    }
    if (cell.obj->type == ObjType::PREDATOR) {
        out << PREDATOR_N;
    }
    if (cell.obj->type == ObjType::PREY) {
        out << PREY_N;
    }
    if (cell.obj->type == ObjType::STONE) {
        out << STONE_N;
    }
    return out;
}

int Cell::getX() const {
    return crd.first;
}

int Cell::getY() const {
    return crd.second;
}

Ocean* Cell::getOcean() const {
    return ocean;
}
