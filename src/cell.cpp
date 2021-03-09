
#include "cell.h"

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
