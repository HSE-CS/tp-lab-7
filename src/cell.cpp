// Copyright 2021 BekusovMikhail

#include "../include/cell.h"

void Cell::init(Pair p, Ocean *oc) {
    this->crd = p;
    this->ocean = oc;
}

Object *Cell::getObject() const {
    return this->obj;
}

void Cell::setObject(Object *obj) {
    this->obj = obj;
}

void Cell::killMe() {
    if (obj) {
        this->ocean->addToKillList(obj);
        this->obj = nullptr;
    }
}

void Cell::setOcean(Ocean *ocean) {
    this->ocean = ocean;
}

Ocean *Cell::getOcean() {
    return this->ocean;
}

Cell *Cell::findEmptyCell() {
    return this->ocean->findEmptyCell({this->crd.x,this->crd.y});
}

Cell *Cell::findPrey() {
    return this->ocean->findPrey({this->crd.x,this->crd.y});
}

