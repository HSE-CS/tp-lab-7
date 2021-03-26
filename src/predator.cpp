// Copyright 2020 Osmanov Islam

#include <fstream>
#include <string>
#include <cmath>
#include "../include/predator.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Predator::Predator(Cell *cell1,
                   int health,
                   int prod,
                   int need) : Prey(cell1, health, prod) {
    this->objType = PREDATOR;
    this->eat = need;
}

Predator::~Predator() {
    delete this->cell;
}



void Predator::live() {
    if (heal == 0) {
        delete this;
        return;
}

    kill();

    if (this->eat == 0) {
        this->heal = this->heal - 1;
    } else {
        if (this->produceRate > this->produceCounter) {
            this->produceCounter += this->produceCounter + 1;
        } else {
            this->produceCounter = 0;
            produce();
        }
    }
}

void Predator::produce() {
    Cell* prod_cell = this->cell->getOcean()->findCell(this->cell);
    if (prod_cell != nullptr) {
        Predator* pred = new Predator(prod_cell);
        prod_cell->setObject(pred);
        this->cell->getOcean()->addObject(pred);
    } else {
        return;
    }
}

void Predator::setCell(Cell* cell1) {
    this->cell = cell1;
}

void Predator::kill() {
    Cell* kill_cell = this->cell->getOcean()->findCell(this->cell);

    if (kill_cell != nullptr) {
        this->eat = this->eat + 1;
        delete kill_cell->getObject();
        kill_cell->setObject(this);
        this->cell->setObject(nullptr);
        setCell(kill_cell);
    } else {
        if (this->eat == 0) {
            move();
            return;
        } else {
            this->eat = this->eat - 1;
        }
    }
}
