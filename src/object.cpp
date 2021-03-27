// Copyright 2021 Smirnov Grigory
#include "../include/object.h"
#include "../include/cell.h"
Object::Object(Cell* c) {
	cell = c;
	type = NOTHING_N;
}

void Object::setCell(Cell* c) {
	cell = c;
}

char Object::getType() {
	return type;
}

void Object::death() {
	status = DEAD;
}

int Object::getStatus() {
	return status;
}
