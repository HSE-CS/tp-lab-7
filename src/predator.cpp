// Copyright 2021 Stolbov Yaroslav
#include "../include/predator.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Predator::Predator(Cell* cell) : Object(cell) {
    setTimeOfLive(TIME_PREY);
    this->type = ObjType::PREY;
    this->isHungry = true;
}

void Predator::live() {
    move();
    time_of_life--;
    if (time_of_life % 5 == 0) {
        isHungry = true;
    }
    if (isHungry && time_of_life) {
        eat();
    } else if (time_of_life % 4 == 0) {
        makeChild();
    } else if (time_of_life == 0) {
        die();
    }
}

char Predator::getSymbol() {
    return PREDATOR_N;
}

void  Predator::move() {
    Cell* newCell = cell->moveToCell();
    if (cell->getObject() == nullptr) {
        this->cell->setObject(nullptr);
        this->setCell(nullptr);
        newCell->setObject(this);
        this->cell = newCell;
    }
}

void Predator::eat() {
    Cell* food = cell->moveToCell();
    if (food->getObject() != nullptr && food->getObject()->getState()) {
        food->getObject()->die();
        time_of_life += 2;
        this->isHungry = false;
    }
}

void Predator::makeChild() {
    Cell* newCell = cell->moveToCell();
    if (newCell->getObject() == nullptr) {
        Object* child = new Predator(newCell);
        cell->getOcean()->addObjectToStuff(child);
        newCell->setObject(child);
    }
}
