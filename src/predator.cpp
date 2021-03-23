// Copyright 2021 Khoroshavina Ekaterina
#include "predator.h"

Predator::Predator(ObjType newObjType, Cell* cell) : Object(newObjType, cell) {
    this->objType = newObjType;
    this->hungry = true;
    this->hp = HP_PREDATOR;
}

Predator::~Predator() {
}

void Predator::live() {
    move();
    hp--;
    if (hp % 4 == 0) {
        hungry = true;
    }
    if (hungry && isAlive()) {
        eat();
    } else if (hp % 6 == 0) {
        breed();
    }   else if (hp == 0) {
        death();
    }
}

void Predator::move() {
    Cell* newCell = cell->makeNewCell();
    if (cell->getObject() == nullptr) {
        cell->setObject(nullptr);
        this->setCell(nullptr);
        newCell->setObject(this);
        cell = newCell;
    }
}

void Predator::eat() {
    Cell* prey = cell->makeNewCell();
    if (prey->getObject() != nullptr && prey->getObject()->isAlive()) {
        prey->getObject()->death();
        hp++;
        this->hungry = false;
    }
}

void Predator::breed() {
    Cell* newCell = cell->makeNewCell();
    if (newCell->getObject() == nullptr) {
        Object* small_predator = new Predator(ObjType::PREDATOR, newCell);
        cell->getOcean()->addObject(small_predator);
        newCell->setObject(small_predator);
    }
}
