// Copyright 2021 Artem Danyaev
#include "../include/cell.h"

Cell::Cell(Pair p, Ocean* oc) : crd(p), ocean(oc) {}

void Cell::init(Pair p, Ocean* oc) {
	crd = p;
	ocean = oc;
}

Object* Cell::getObject() const { return obj; }

void Cell::setObject(Object* o) { obj = o; }

Pair Cell::getCoords() { return crd; }

Ocean* Cell::getOcean() { return ocean; }
