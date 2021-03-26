// Copyright 2021 Vlad
#include "Object.h"
#include <iostream>

void Object::setCell(Cell* cell) {
    this->cell = cell;
}

void Object::move() {
    int x = std::rand() % 3 - 1;
    int y = std::rand() % 3 - 1;
    Pair pair = { x, y };
    Cell* newCell = getNewCell(pair);
    for (int i = 0; i < 20; i++) {
        if (newCell && !newCell->getObject()) {
            this->cell->removeObj();
            newCell->addObject(this);
            this->cell = newCell;
            return;
        }
        x = std::rand() % 3 - 1;
        y = std::rand() % 3 - 1;
        pair = { cell->getX() + x, cell->getY() + y };
        newCell = getNewCell(pair);
    }
}

Cell* Object::getCell() {
    return cell;
}

ObjType Object::getType() {
    return this->type;
}

Cell* Object::getNewCell(Pair pair) {
    return cell->getOcean()->getCell(pair);
}

Cell* Object::reproduct() {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            Pair pair = { cell->getX() + i, cell->getY() + j };
            Cell* newCell = getNewCell(pair);
            if (newCell  && !newCell->getObject()) {
                return newCell;
            }
        }
    }
    return nullptr;
}
