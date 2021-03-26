// Copyright 2021 Nikolaev Ivan

#include <iostream>
#include "prey.h"
#include "cell.h"
#include "ocean.h"

Prey::Prey() {
    this->symbol = 'f';
}

Prey::Prey(int health) {
    this->symbol = 'f';
    this->health = health;
    this->maxHealth = health;
}

bool Prey::checkPosition(int x, int y) {
    if (x < 0 || y < 0 || cell->getOcean()->getHeight() <= x ||
        cell->getOcean()->getWidth() <= y) {
        return false;
    }
    else {
        return true;
    }
}

void Prey::live() {
    health--;
    if (health <= 0) {
        die();
        return;
    }
    if (health < maxHealth * 40 / 100) {
        abilityToReproduce = true;
    }
    move();
}

void Prey::die() {
    Pair crd = this->cell->getCrd();
    this->cell->getOcean()->setPreys(this->cell->getOcean()->getPreys() - 1);
    this->cell->getOcean()->setCell(crd.x, crd.y, nullptr);
    this->cell->getOcean()->deleteObj(this);
}

void Prey::changeCell(int x, int y) {
    Pair oldCrd = this->cell->getCrd();
    this->cell->getOcean()->setCell(oldCrd.x, oldCrd.y, nullptr);
    this->cell = &this->cell->getOcean()->getCells()[x][y]; // изменить в тек. объекте
    this->cell->setCrd({x, y});
    this->cell->getOcean()->setCell(x, y, this);
}

bool Prey::moveTo(int x, int y) {
    Cell** cells = cell->getOcean()->getCells();
    if (checkPosition(x, y) && cells[x][y].getObject() == nullptr) {
        changeCell(x, y);
        return true;
    } else {
        return false;
    }
}

void Prey::move() {
    Pair crd = this->cell->getCrd();
    int dest = rand() % 4;
    bool isMoved = false;
    switch (dest) {
    case 0:
        isMoved = moveTo(crd.x, crd.y + 1);
        if (isMoved) {
            break;
        }
    case 1:
        isMoved = moveTo(crd.x + 1, crd.y);
        if (isMoved) {
            break;
        }
    case 2:
        isMoved = moveTo(crd.x, crd.y - 1);
        if (isMoved) {
            break;
        }
    case 3:
        isMoved = moveTo(crd.x - 1, crd.y);
        break;
    }
    bool isSexualPartnerFinded = false;
    if (abilityToReproduce == true) {
        isSexualPartnerFinded = searchSexualPartner();
    }
    if (isSexualPartnerFinded == true && isMoved) {
        leaveOffspring(crd.x, crd.y);
        return;
    }
    if (isMoved) {
        this->cell->getOcean()->setCell(crd.x, crd.y, nullptr);
    }
}

void Prey::leaveOffspring(int x, int y) {
    this->cell->getOcean()->setCell(x, y, new Prey(this->maxHealth));
    Object* offspring = this->cell->getOcean()->getCells()[x][y].getObject();
    this->cell->getOcean()->addObject(x, y, offspring);
    this->cell->getOcean()->setPreys(this->cell->getOcean()->getPreys() + 1);
}

bool Prey::searchSexualPartner() {
    bool isPartnerFinded = false;
    int x = cell->getCrd().x;
    int y = cell->getCrd().y;
    if (checkCellForReproduce(x + 1, y) || checkCellForReproduce(x, y + 1) ||
        checkCellForReproduce(x - 1, y) || checkCellForReproduce(x, y - 1)) {
        isPartnerFinded = true;
    }
    return isPartnerFinded;
}

bool Prey::checkCellForReproduce(int x, int y) {
    Cell** cells = cell->getOcean()->getCells();
    char symbolOfSpecie = this->getSymbol();
    if (checkPosition(x, y) && cells[x][y].getObject() != nullptr &&
        cells[x][y].getObject()->getSymbol() == symbolOfSpecie) {
        return true;
    } else {
        return false;
    }
}

char Prey::getSymbol() {
    return symbol;
}