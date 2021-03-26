// Copyright 2021 Nikolaev Ivan

#include <iostream>
#include "predator.h"
#include "ocean.h"
#include "cell.h"

Predator::Predator() {
    this->symbol = 'S';
}

Predator::Predator(int health) {
    this->symbol = 'S';
    this->health = health;
    this->maxHealth = health;
}

void Predator::live() {
    health--;
    satiety--;
    if (health <= 0) {
        die();
        return;
    }
    if (health < maxHealth * 50 / 100) {
        abilityToReproduce = true;
    }
    move();
}

void Predator::die() {
    Pair crd = this->cell->getCrd();
    this->cell->getOcean()->setPredators(this->cell->getOcean()->getPredators() - 1);
    this->cell->getOcean()->setCell(crd.x, crd.y, nullptr);
    this->cell->getOcean()->deleteObj(this);}

void Predator::move() {
    Pair crd = this->cell->getCrd();
    Cell** cells = cell->getOcean()->getCells();
    int dest = rand() % 4;
    Pair crd2 = eat();
    if (crd2.x != -1) {
        dest = -1;
    }
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
    if (dest == -1) {
        this->cell->getOcean()->getCells()[crd2.x][crd2.y].getObject()->die();
        moveTo(crd2.x, crd2.y);
    }
    bool isSexualPartnerFinded = false;
    if (abilityToReproduce == true) {
        isSexualPartnerFinded = searchSexualPartner();
    }
    if (isSexualPartnerFinded == true && isMoved && satiety > 5) {
        leaveOffspring(crd.x, crd.y);
        return;
    }
    if (isMoved) {
        this->cell->getOcean()->setCell(crd.x, crd.y, nullptr);
    }
}

void Predator::leaveOffspring(int x, int y) {
    this->cell->getOcean()->setCell(x, y, new Predator(this->maxHealth));
    Object* offspring = this->cell->getOcean()->getCells()[x][y].getObject();
    this->cell->getOcean()->addObject(x, y, offspring);
    this->cell->getOcean()->setPredators(this->cell->getOcean()->getPredators() + 1);
}

Pair Predator::eat() {
    Cell** cells = cell->getOcean()->getCells();
    int x = cell->getCrd().x;
    int y = cell->getCrd().y;
    Pair pair = { -1, -1 };
    if (checkPosition(x + 1, y) && cell->getOcean()->getCells()[x + 1][y].getObject() != nullptr && cells[x + 1][y].getObject()->getSymbol() == 'f') {
        pair = { x + 1, y };
    }
    else if (checkPosition(x, y + 1) && cell->getOcean()->getCells()[x][y + 1].getObject() != nullptr && cells[x][y + 1].getObject()->getSymbol() == 'f') {
        pair = { x, y + 1 };
    }
    else if (checkPosition(x, y - 1) && cell->getOcean()->getCells()[x][y - 1].getObject() != nullptr && cells[x][y - 1].getObject()->getSymbol() == 'f') {
        pair = { x, y - 1 };
    }
    else if (checkPosition(x - 1, y) && cell->getOcean()->getCells()[x - 1][y].getObject() != nullptr && cells[x - 1][y].getObject()->getSymbol() == 'f') {
        pair = { x - 1, y };
    }
    if (pair.x != -1) {
        satiety += 10;
    }
    return pair;
}

char Predator::getSymbol() {
    return symbol;
}