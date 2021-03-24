// Copyright 2021 Igumnova Natasha
#include <fstream>
#include <string>
#include <cmath>
#include "../include/predator.h"
#include "../include/cell.h"
#include "../include/ocean.h"

Predator::~Predator() {
    delete cell;
}
void Predator::live() {
    if (health == 0) {
        delete this;
        return;
    }
    eat();
    if (hunger > 0) {
        if (multCounter >= multiPoint) {
            multCounter = 0;
            multi();
        } else {
            multCounter += 1;
        }
    } else {
        health -= 1;
    }
}
void Predator::setCell(Cell* cell_) {
    cell = cell_;
}

void Predator::eat() {
    Cell* cell_for_eat = cell->getOcean()->findCell(cell);
    if (cell_for_eat == nullptr) {
        if (hunger > 0)
            hunger -= 1;
        move();
        return;
    }
    delete cell_for_eat->getObject();
    cell_for_eat->setObject(this);
    cell->setObject(nullptr);
    setCell(cell_for_eat);
    hunger += 1;
}
void Predator::multi() {
    Cell* cell_for_multi = cell->getOcean()->findCell(cell);
    if (cell_for_multi == nullptr) {
        return;
    }
    Predator* predator = new Predator(cell_for_multi);
    cell_for_multi->setObject(predator);
    cell->getOcean()->addObject(predator);
}
