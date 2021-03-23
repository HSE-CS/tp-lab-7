// Copyright 2021 Dmitry Vargin
#include "../include/prey.h"
#include "../include/ocean.h"

void Prey::live() {
    if (--this->life_time < 1) {
        this->cell->setObject(nullptr);
        return;
    }
    this->goToCell(this->getNextCell());
}

Cell *Prey::getNextCell() {
    std::vector<Cell *> variants;
    if (cell->crd.first > 0 &&
            !this->cell->getOcean()->get(
                    this->cell->crd.first-1,
                    this->cell->crd.second)->hasObject()) {
        variants.push_back(
                this->cell->getOcean()->get(
                        this->cell->crd.first-1,
                        this->cell->crd.second));
    }
    if (cell->crd.first < cell->getOcean()->lenX() - 1 &&
            !this->cell->getOcean()->get(
                    this->cell->crd.first+1,
                    this->cell->crd.second)->hasObject()) {
        variants.push_back(
                this->cell->getOcean()->get(
                        this->cell->crd.first+1,
                        this->cell->crd.second));
    }
    if (cell->crd.second > 0 &&
            !this->cell->getOcean()->get(
                    this->cell->crd.first,
                    this->cell->crd.second-1)->hasObject()) {
        variants.push_back(
                this->cell->getOcean()->get(
                        this->cell->crd.first,
                        this->cell->crd.second-1));
    }
    if (cell->crd.second < cell->getOcean()->lenY() - 1 &&
            !this->cell->getOcean()->get(
                    this->cell->crd.first,
                    this->cell->crd.second+1)->hasObject()) {
        variants.push_back(
                this->cell->getOcean()->get(
                        this->cell->crd.first,
                        this->cell->crd.second+1));
    }
    if (variants.empty()) {
        return this->cell;
    }
    int i = cell->getOcean()->RANDOMER() % variants.size();
    return variants[i];
}

void Prey::goToCell(Cell *c) {
    this->cell->setObject(nullptr);
    float x = (this->std_life_time - this->life_time) * 1.0f;
    float chance = sqrt(x) / pow(sqrt(this->life_time), 3);
    float r = cell->getOcean()->RANDOMER() % RAND_MAX;
    if (r < chance) {
        Cell *first_cell = this->cell;
        Cell *second_cell = getNextCell();

        Prey *prey = new Prey(first_cell, std_life_time);
        first_cell->setObject(prey);

        this->cell = second_cell;
        this->cell->setObject(this);
    } else {
        Cell *cell1 = getNextCell();
        this->cell->setObject(nullptr);
        this->cell = cell1;
        this->cell->setObject(this);
    }
}
