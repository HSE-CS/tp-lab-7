//
// Created by Данил on 04.03.2021.
//

#include "../include/Space.h"
#include "Objects.h"

Cell::Cell(Object *object1) {
    this->object = object1;
    this->filler = object1->getFiller();
}

Cell::~Cell() {
    this->object = nullptr;
}

char Cell::getFiller() {
    return this->filler;
}

void Cell::setFiller(char c) {
    this->filler = c;
}

Object *Cell::getObject() {
    return this->object;
}

void Cell::setObject(Object *object1) {
    this->object = object1;
}
