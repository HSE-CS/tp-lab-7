// Copyright 2020 Konina Tatiana

#include "../include/cell.h"


void Cell::init(Pair p, Ocean* oc) {
	this->crd = p;
	this->ocean = oc;
}

Object* Cell::getObject() const {
	if (obj) {
		return obj;
	} else {
		return nullptr;
	}
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
Cell* Cell::moveToCell() {
	return ocean->moveObj(crd);
}

Ocean* Cell::getOcean() {
	return this->ocean;
}



