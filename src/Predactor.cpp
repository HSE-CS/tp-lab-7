// Copyright 2021 Vlad
#include "Predactor.h"

void Predactor::live() {
    if (isHungry) {
        Cell* newCell = FindPrey();
        if (newCell) {
            newCell->killMe();
            isHungry = false;
            timeTodeath = death;
            timeToReproduction--;
            cell->removeObj();
            newCell->addObject(this);
            this->cell = newCell;
            return;
        } else {
            if (timeTodeath == 0) {
                this->cell->killMe();
                return;
            }
            timeTodeath--;
        }
    } else {
        if (timeToReproduction == 0) {
            Cell* newCell = reproduct();
            if (newCell) {
                Object* child = new Predactor(newCell, 
                    timeToReproduction, timeTodeath);
                child->setCell(newCell);
                cell->setObject(child);
            }
            timeToReproduction = reproduction + 1;
        }
        timeToReproduction--;
        isHungry = true;
    }
    move();
}

Cell* Predactor::FindPrey() {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            Pair pair = { cell->getX() + i, cell->getY() + j };
            Cell* newCell = getNewCell(pair);
            if (newCell && newCell->getObject() && 
                newCell->getObject()->getType() == ObjType::PREY) {
                return newCell;
            }
        }
    }
    return nullptr;
}
