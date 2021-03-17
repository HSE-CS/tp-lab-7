// Copyright 2021 valvarl

#include "object.h"

Object::Object(Cell * _cell) {
    cell = _cell;
}

void Object::setCell(Cell *c) {
    cell = c;
}

Object::~Object() {

}

ObjType Object::getType() const {
    return type;
}

int Object::getRemainLive() const {
    return remain_live;
}

Cell *Object::getCell() const {
    return cell;
}

void Object::setRemainLive(int remainLive) {
    remain_live = remainLive;
}
