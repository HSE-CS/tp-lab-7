//  Copyright 2021 Nikita Naumov

#include "../include/predator.h"
#include "../include/Object.h"
#include "../include/cell.h"

Predator::Predator(Cell *thisCell) : Object(thisCell) {
    this->cell = thisCell;
    this->hunger = 100;
}

void Predator::live() {

}

void Predator::setType() {

}