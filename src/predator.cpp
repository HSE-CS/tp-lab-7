// Copyright 2021 Golovanov
#include "../include/predator.h"
#include "../include/cell.h"

Predator::Predator(Cell* cell) : Prey(cell) {
    this->type = PREDATOR_N;
    this->Life_time = 5;
    this->number_of_fish_eaten = 0;
}

void Predator::live() {
    if (Life_time > 0) {
        Cell* ptr_cell = this->cell->hunt();
        if (ptr_cell) {
            number_of_fish_eaten += 1;
            ptr_cell->killMe();
            cell->setObject(nullptr);
            cell = ptr_cell;
            cell->setObject(this);
            Life_time += 1;
        } else {
            ptr_cell = cell->seachEmptyPlace();
            if (ptr_cell) {
                cell->setObject(nullptr);
                cell = ptr_cell;
                cell->setObject(this);
            }
        }
        this->breeding();
        Life_time--;
    } else {
        this->cell->killMe();
    }
}

void Predator::breeding() {
    if (number_of_fish_eaten >= 2) {
        Cell* ptr_cell = cell->seachEmptyPlace();
        if (ptr_cell) {
        auto* ptr_predator = new Predator(ptr_cell);
        ptr_cell->setObject(ptr_predator);
        ptr_cell->getOcean()->addObject(ptr_predator);
        }
        number_of_fish_eaten -= 2;
    }
}
