
#include "../include/predator.h"

void Predator::live() {
    if (--this->life_time < 1) {
        this->cell->setObject(nullptr);
        return;
    }
    this->goToCell(this->getNextCell());
}

Cell *Predator::getNextCell() {
    std::vector<Cell *> eat;
    std::vector<Cell *> free;
    Cell *tmp_c;
    int tmp_t;
    if (cell->crd.first > 0) {
        tmp_c = cell->getOcean()->get(
                cell->crd.first-1,
                cell->crd.second);
        if (tmp_c->hasObject()) {
            tmp_t = (int) tmp_c->getObject()->getType();
            if (0 <= tmp_t && tmp_t <= 1) {
                eat.push_back(tmp_c);
            }
        } else {
            free.push_back(tmp_c);
        }
    }
    if (cell->crd.first < cell->getOcean()->lenX() - 1) {
        tmp_c = cell->getOcean()->get(
                cell->crd.first+1,
                cell->crd.second);
        if (tmp_c->hasObject()) {
            tmp_t = (int) tmp_c->getObject()->getType();
            if (0 <= tmp_t && tmp_t <= 1) {
                eat.push_back(tmp_c);
            }
        } else {
            free.push_back(tmp_c);
        }
    }
    if (cell->crd.second > 0) {
        tmp_c = cell->getOcean()->get(
                cell->crd.first,
                cell->crd.second-1);
        if (tmp_c->hasObject()) {
            tmp_t = (int) tmp_c->getObject()->getType();
            if (0 <= tmp_t && tmp_t <= 1) {
                eat.push_back(tmp_c);
            }
        } else {
            free.push_back(tmp_c);
        }
    }
    if (cell->crd.second < cell->getOcean()->lenY() - 1) {
        tmp_c = cell->getOcean()->get(
                cell->crd.first,
                cell->crd.second+1);
        if (tmp_c->hasObject()) {
            tmp_t = (int) tmp_c->getObject()->getType();
            if (0 <= tmp_t && tmp_t <= 1) {
                eat.push_back(tmp_c);
            }
        } else {
            free.push_back(tmp_c);
        }
    }
    int i;
    if (eat.empty()) {
        if (free.empty())
            return this->cell;
        i = rand() % free.size();
        return free[i];
    }
    i = rand() % eat.size();
    return eat[i];
}

void Predator::goToCell(Cell *c) {
    bool canGiveOffSpring = life_time > std_life_time / 2;
    this->cell->setObject(nullptr);
    float x = (this->std_life_time - this->life_time) * 1.0f;
    float chance = sqrt(x) /
            pow(sqrt(sqrt(sqrt(this->life_time))), 3);
    float r = rand() % RAND_MAX;
    if (r < chance && canGiveOffSpring) {
        Cell *first_cell = this->cell;
        Cell *second_cell = getNextCell();

        Predator *prey = new Predator(first_cell, std_life_time);
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
