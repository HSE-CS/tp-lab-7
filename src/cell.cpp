// Copyright 2021 Stifeev Nikita

#include "../include/ocean.h"
#include "../include/cell.h"

Object* Cell::getObject() const {
    return obj;
}

void Cell::setObject(Object* obj) {
    this->obj = obj;
}

Pair Cell::getCrd() {
    return crd;
};

vector<Cell*>* Cell::getEmptyCells() {
    return ocean->getEmptyCells(this);
}

void Cell::addToOcean(Object* obj) {
    ocean->addObject(obj);
}

vector<Cell*>* Cell::getPreyCells() {
    return ocean->getCellsWithPrey(this);
}

void Cell::killMe() {
    ocean->killObject(this);
}
