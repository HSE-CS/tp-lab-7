
#include "cell.h"
#include "ocean.h"

Object* Cell::getObject() const {
	return this->obj;
}

void Cell::init(Pair p, Ocean* oc) {
	crd = p;
	ocean = oc;
}

void Cell::setObject(Object* obj) {
	this->obj = obj;
}

Ocean* Cell::getOcean() {
	return this->ocean;
}

void Cell::killMe(Object* fdel) {
	this->obj = nullptr;
}

void Cell::delObj() {
	this->obj = nullptr;
}

Pair Cell::getCord() {
	return this->crd;
}