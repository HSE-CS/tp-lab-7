// Copyright 2020 Osmanov Islam


#include <cmath>
#include <string>
#include <fstream>
#include "../include/prey.h"
#include "../include/cell.h"
#include "../include/ocean.h"

void Prey::live() {
    if (heal == 0) {
        delete this;
        return;
    }
    if(produceRate > produceCounter)
    {
        produceCounter++;
        move();
    } else {
        produceCounter = 0;
        produce();
    }
    heal -= 1;
}

Prey::Prey(Cell *cell1, int health, int beed) : Object(PREY, cell1) {
    this->cell = cell1;
    this->heal = health;
    this->produceRate = beed;
}

Prey::~Prey() {
    delete cell;
}

void Prey::produce() {
    Cell* producing_cell = cell->getOcean()->findCell(cell);
    if (producing_cell == nullptr) {
        return;
    } else {
        Prey* child = new Prey(producing_cell);
        producing_cell->setObject(child);
        cell->getOcean()->addObject(child);
    }
}

void Prey::move() {
    Cell* moving_cell = cell->getOcean()->findCell(cell);
    if (moving_cell == nullptr) {
        return;
    } else {
        cell->setObject(nullptr);
        moving_cell->setObject(this);
        setCell(moving_cell);
    }

}

void Prey::setCell(Cell* cell1) {
    cell = cell1;
}