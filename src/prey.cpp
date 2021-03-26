// copyright 2021 Victor Shatilov

#include "../include/prey.h"
#include "../include/cell.h"
#include "../include/Ocean.h"

#include "common.h"

prey::prey(int x, int y, int energy,
           int type, Cell *cell) : Object(x, y,
                                          energy, type, cell) {

}

void prey::live() {
    this->setEnergy(this->getEnergy() + 1);
    std::random_device basic;
    int moveTo = static_cast<signed>(basic() % 4);
    switch (moveTo) {
        case UP:
            if (this->cell->getUp()->getObject() == nullptr) {
                this->cell->setObject(nullptr);
                this->cell->getUp()->setObject(this);
                this->y = (y - 1 + height) % height;
                setCell(cell->getUp());
            }
            break;
        case RIGHT:
            if (this->cell->getRight()->getObject() == nullptr) {
                this->cell->setObject(nullptr);
                this->cell->getRight()->setObject(this);
                this->x = (x + 1) % width;
                setCell(cell->getRight());
            }
            break;
        case DOWN:
            if (this->cell->getDown()->getObject() == nullptr) {
                this->cell->setObject(nullptr);
                this->cell->getDown()->setObject(this);
                this->y = (y + 1) % height;
                setCell(cell->getDown());
            }
            break;
        case LEFT:
            if (this->cell->getLeft()->getObject() == nullptr) {
                this->cell->setObject(nullptr);
                this->cell->getLeft()->setObject(this);
                this->x = (x - 1 + width) % width;
                setCell(cell->getLeft());
            }
            break;
        default:
            break;
    }
}

Object *prey::divide() {
    int newX = -1, newY = -1;
    Cell *newCell = nullptr;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (this->cell->getOcean()->getCell(j,
                                                i)->getObject() == nullptr) {
                newX = j;
                newY = i;
                newCell = this->cell->getOcean()->getCell(j, i);
            }
        }
    }
    if (newCell == nullptr) {
        return nullptr;
    }
    auto child = new prey(newX, newY,
                          startPreyEnergy, PREY, newCell);
    newCell->setObject(child);
    this->energy -= startPreyEnergy;
    return child;
}

char prey::getFiller() {
    return prey_symbol;
}
