// Copyright 2021 Smirnov Grigory
#include "../include/cell.h"
#include "../include/ocean.h"

void Cell::init(Pair p, Ocean* oc) {
	ocean = oc;
	crd = p;
}

Object* Cell::getObject() const {
	return obj;
}

void Cell::setObject(Object* o) {
	obj = o;
	o->setCell(this);
}

void Cell::setNull() {
	obj = nullptr;
}

Cell* Cell::getTop() {
	if (crd.x == 0)
		return &ocean->cells[ocean->n - 1][crd.y];
	return &ocean->cells[crd.x - 1][crd.y];
}

Cell* Cell::getBot() {
	if (crd.x == ocean->n - 1)
		return &ocean->cells[0][crd.y];
	return &ocean->cells[crd.x + 1][crd.y];
}

Cell* Cell::getLeft() {
	if (crd.y == 0)
		return &ocean->cells[crd.x][ocean->m - 1];
	return &ocean->cells[crd.x][crd.y - 1];
}

Cell* Cell::getRight() {
	if (crd.y == ocean->m - 1)
		return &ocean->cells[crd.x][0];
	return &ocean->cells[crd.x][crd.y + 1];
}
