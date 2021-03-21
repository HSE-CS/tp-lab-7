// Copyright 2021 BekusovMikhail

#include "../include/predator.h"
#include "../include/cell.h"

Predator::Predator(Cell *cell) : Prey(cell) {
    this->type = PREDATOR_N;
    this->leftTime = PredatorLife;
    this->leftToBirth = PredatorBirth;
    this->eatenPreys = 0;
}

void Predator::live() {
    this->leftTime--;
    if (this->leftTime <= 0) {
        this->cell->killMe();
        return;
    }
    Cell *tmpCell = this->cell->findPrey();
    if (tmpCell) {
        this->eatenPreys += 1;
        tmpCell->killMe();
        this->cell->setObject(nullptr);
        this->cell = tmpCell;
        this->cell->setObject(this);
        this->leftTime += PredatorAdditionalTime;
    } else {
        tmpCell = cell->findEmptyCell();
        if (tmpCell) {
            this->cell->setObject(nullptr);
            this->cell = tmpCell;
            this->cell->setObject(this);
        }
    }
    this->giveBirth();
}

void Predator::giveBirth() {
    this->leftToBirth--;
    if (this->leftToBirth <= 0 && this->eatenPreys >= EatenPreysToBirth) {
        Cell *tmpCell = cell->findEmptyCell();
        if (tmpCell) {
            auto *tmpPredator = new Predator(tmpCell);
            tmpCell->setObject(tmpPredator);
            tmpCell->getOcean()->addObject(tmpPredator);
        }
        this->leftToBirth = PredatorBirth;
        this->eatenPreys -= EatenPreysToBirth;
    }
}
