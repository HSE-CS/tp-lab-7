// Copyright 2021 VladimirUspensky

#include "../include/object.h"

Object::Object(Cell * c) {
    this->cell = c;
}

Object::~Object() {

}

ObjType Object::getType() const {
    return this->type;
}

Cell *Object::getCell() const {
    return this->cell;
}

void Object::setRemainLive(int remainLive) {
    this->remain_live = remainLive;
}


void Object::setCell(Cell *c) {
    this->cell = c;
}

int Object::getRemainLive() const {
    return this->remain_live;
}
