// Copyright GN 2021
#include "cell.h"
#include "ocean.h"
class Object;
Pair Cell::getCoordinates() {
	return this->crd;
}
void Cell::setObject(Object* obj) {
	this->obj = obj;
}
void Cell::init(Pair p, Ocean* oc) {
	crd = p;
	ocean = oc;
}
Object* Cell::getObject() const {
	return this->obj;
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
