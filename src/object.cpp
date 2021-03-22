// Copyright 2021 Smirnov Grigory
#include "../include/object.h"
#include "../include/cell.h"
Object::Object(Cell* c = nullptr) {
	cell = c;
	type = NOTHING_N;
}

void Object::setCell(Cell* c) {
	cell = c;
}

char Object::getType() {
	return type;
}
