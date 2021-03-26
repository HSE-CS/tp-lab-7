// Copyright 2021 Artem Danyaev
#include <ctime>
#include "../include/predator.h"

Predator::Predator(Cell* c) : Object(ObjType::PREDATOR, c) {}

Cell* Predator::findPrey() {
    unsigned int seed = time(nullptr);
    std::vector<Pair> offsets;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            offsets.push_back(Pair{ i, j });
        }
    }
    while (!offsets.empty()) {
        int pos = rand_r(&seed) % offsets.size();
        Pair crd = cell->getCoords();
        Pair tcrd = { crd.x + offsets[pos].x, crd.y + offsets[pos].y };
        if (checkIfCellExists(tcrd) &&
            cell->getOcean()->getCell(tcrd)->getObject() != nullptr &&
            cell->getOcean()->getCell(tcrd)->getObject()->getType() == ObjType::PREY) {
            return cell->getOcean()->getCell(tcrd);
        }
        else {
            offsets.erase(offsets.begin() + pos);
        }
    }
    return nullptr;
}

void Predator::live() {
    if (needFoodAfter == 0) {
        Cell* preyCell = findPrey();
        if (preyCell != nullptr) {
            cell->getOcean()->deleteObject(preyCell->getObject());
            preyCell->setObject(this);
            cell->setObject(nullptr);
            cell = preyCell;
            needFoodAfter = predatorNeedFoodAfter;
            timeInHunger = 0;
        }
        else {
            if (timeInHunger >= predatorLifetimeWithoutFood) {
                cell->getOcean()->deleteObject(this);
                cell->setObject(nullptr);
            }
            else {
                timeInHunger++;
                Cell* newcell = findFreeNeighbour();
                if (newcell != nullptr) {
                    newcell->setObject(this);
                    cell->setObject(nullptr);
                    cell = newcell;
                }
            }
        }
        return;
    }
    else {
        Cell* newcell = findFreeNeighbour();
        if (newcell != nullptr) {
            newcell->setObject(this);
            cell->setObject(nullptr);
            if (reprTime == 0) {
                Predator* newPredator = new Predator(cell);
                cell->setObject(newPredator);
                cell->getOcean()->addObject(newPredator);
                reprTime = predatorReprTime;
            }
            cell = newcell;
        }
        needFoodAfter--;
    }
    if (reprTime > 0) {
        reprTime--;
    }
}
