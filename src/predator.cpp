#include "../include/predator.h"
#include "../include/cell.h"
#include "../include/Ocean.h"

predator::predator(int x, int y, int energy, int type, Cell *cell) : Object(x, y, energy, type, cell) {

}

void predator::live() {
    this->setEnergy(this->getEnergy() - 1);
    std::random_device basic;
    int moveTo = static_cast<signed>(basic() % 4);

    // Try to eat someone:

    if (this->cell->getUp()->getObject()->getType() == PREY) {
        this->cell->setObject(nullptr);
        this->cell->getUp()->setObject(this);
        this->y = (y - 1 + height) % height;
        this->energy += startPreyEnergy / 2;
        return;
    }
    if (this->cell->getRight()->getObject()->getType() == PREY) {
        this->cell->setObject(nullptr);
        this->cell->getRight()->setObject(this);
        this->x = (x + 1) % width;
        this->energy += startPreyEnergy / 2;
        return;
    }
    if (this->cell->getDown()->getObject()->getType() == PREY) {
        this->cell->setObject(nullptr);
        this->cell->getDown()->setObject(this);
        this->y = (y + 1) % height;
        this->energy += startPreyEnergy / 2;
        return;
    }
    if (this->cell->getLeft()->getObject()->getType() == PREY) {
        this->cell->setObject(nullptr);
        this->cell->getLeft()->setObject(this);
        this->x = (x - 1 + width) % width;
        this->energy += startPreyEnergy / 2;
        return;
    }

    // Else move like a prey:

    switch (moveTo) {
        case UP:
            if (this->cell->getUp()->getObject() == nullptr) {
                this->cell->setObject(nullptr);
                this->cell->getUp()->setObject(this);
                this->y = (y - 1 + height) % height;
            }
            break;
        case RIGHT:
            if (this->cell->getRight()->getObject() == nullptr) {
                this->cell->setObject(nullptr);
                this->cell->getRight()->setObject(this);
                this->x = (x + 1) % width;
            }
            break;
        case DOWN:
            if (this->cell->getDown()->getObject() == nullptr) {
                this->cell->setObject(nullptr);
                this->cell->getDown()->setObject(this);
                this->y = (y + 1) % height;
            }
            break;
        case LEFT:
            if (this->cell->getLeft()->getObject() == nullptr) {
                this->cell->setObject(nullptr);
                this->cell->getLeft()->setObject(this);
                this->x = (x - 1 + width) % width;
            }
            break;
        default:
            break;
    }
}

Object *predator::divide() {
    int newX = -1, newY = -1;
    Cell *newCell = nullptr;
    for (int i = height - 1; i > -1; --i) {
        for (int j = width - 1; j > -1; --j) {
            if (this->cell->getOcean()->getCell(j, i)->getObject() == nullptr) {
                newX = j;
                newY = i;
                newCell = this->cell->getOcean()->getCell(j, i);
            }
        }
    }
    if (newCell == nullptr) {
        return nullptr;
    }
    auto child = new predator(newX, newY, startPreyEnergy, PREY, newCell);
    newCell->setObject(child);
    this->energy -= startPreyEnergy;
    return child;
}

char predator::getFiller() {
    return predator_symbol;
}
