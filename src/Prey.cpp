//  Copyright 2021 Kartseva Masha
#include "Prey.h"
#include <iostream>

Prey::Prey(Cell* c) :Object(c) {
    this->lifetime = LTPrey;
    type = ObjType::PREY;
}
void Prey::live() {
    move();
    if (lifetime < 0.5 * LTPrey)
        copulation();
    lifetime--;
}
char Prey::getSymbol() {
    return PREY_N;
}
void Prey::move() {
    Cell* newCell = cell->FREE();
    if (newCell) {
        this->getCell()->Moving();
        newCell->setObject(this);
        this->cell = newCell;
    }
}
void Prey::copulation() {
    Cell* newCell = cell->FREE();
    if (newCell) {
        Object* child = new Prey(newCell);
        newCell->setObject(child);
        cell->getOcean()->AddStuff(child);
    }
}
