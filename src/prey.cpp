// Copyright 2021 BekusovMikhail

#include "../include/prey.h"
#include "../include/common.h"
#include "../include/ocean.h"

Prey::Prey(Cell *cell) : Object(cell) {
    this->leftTime = PreyLife;
    this->leftToBirth = PreyBirth;
    this->type = PREY_N;
}

void Prey::live() {
    this->leftTime--;
    if (this->leftTime > 0) {
        Cell *tmpCell = cell->findEmptyCell();
        if (tmpCell) {
            this->cell->setObject(nullptr);
            this->cell = tmpCell;
            this->cell->setObject(this);
        }
        this->giveBirth();
    } else this->cell->killMe();
}

void Prey::giveBirth() {
    this->leftToBirth--;
    if (this->leftToBirth == 0) {
        Cell *tmpCell = cell->findEmptyCell();
        if (tmpCell) {
            Prey *tmpPrey = new Prey(tmpCell);
            tmpCell->setObject(tmpPrey);
            tmpCell->getOcean()->addObject(tmpPrey);
        }
        this->leftToBirth = PreyBirth;
    }
}
