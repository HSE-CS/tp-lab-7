// Copyright 2021 Elise
#include "cell.h"
#include "ocean.h"

void Cell::init(Pair p, Ocean* oc) {
  this->crd = p;
  this->ocean = oc;
}

Object* Cell::getObject() const {
	return obj;
}

void Cell::setObject(Object* object_new) {
	this->obj = object_new;
}

void Cell::killMe() {
  this->obj = nullptr;
}

Ocean* Cell::getOcean() {
	return this->ocean;
}

Cell* Cell::newCell() {
	return ocean->coordinates(crd);
}

Cell* Cell::lets_go_eat() {
	return ocean->lets_go_eat({crd.x_, crd.y_});
}
