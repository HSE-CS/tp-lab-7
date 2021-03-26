// Copyright JMax 2021
#include <vector>

#include "../include/Predator.h"

void Predator::decreaseSatiety() {
    satiety *= SATIETY_DECREASE;
}

bool Predator::isHungry() const {
    return satiety < size;
}

bool Predator::isVeryHungry() const {
    return satiety < static_cast<double>(size) / 100;
}

void Predator::live() {
    if (isAlive()) {
        if (satiety < static_cast<double>(size) / 10000) {
            death();
            return;
        }
        decreaseSatiety();
        Prey::live();
    }
}

void Predator::move() {
    Pair crd = cell->getCoordinates();
    std::vector <Cell*> emptyCells;
    std::vector <Cell*> preyCells;
    std::vector <Cell*> predatorCells;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            Cell* cellToMove = cell->getCell({ crd.x + i, crd.y + j });
            if (isPrey(cellToMove)) {
                preyCells.push_back(cellToMove);
            } else if (isEmpty(cellToMove)) {
                emptyCells.push_back(cellToMove);
            } else if (isFriend(cellToMove)) {
                predatorCells.push_back(cellToMove);
            }
        }
    }

    std::vector<Cell*> food;
    if (isVeryHungry()) {
        if (preyCells.empty() && predatorCells.empty()) {
            food = emptyCells;
        } else {
            food = uniteVectors(preyCells, predatorCells);
        }
    } else if (isHungry()) {
        if (preyCells.empty()) {
            food = emptyCells;
        } else {
            food = preyCells;
        }
    } else {
        food = emptyCells;  // uniteVectors(preyCells, emptyCells);
    }

    if (!food.empty()) {
        eat(getCell(food), !predatorCells.empty());
    }
}

std::vector<Cell *> Predator::uniteVectors(std::vector<Cell*> vector1,
                                           std::vector<Cell*> vector2) {
    std::vector<Cell*> food;
    int size = vector1.size() + vector2.size();
    for (int i = 0; i < size; i++) {
        if (i < vector1.size()) {
            food.push_back(vector1[i]);
        } else {
            food.push_back(vector2[i - vector1.size()]);
        }
    }
    return food;
}

bool Predator::isPrey(Cell *cell) {
    return cell->getType() == PREY;
}

void Predator::eat(Cell* dest, bool hasFriends) {
    if (dest->getType() == PREY || dest->getType() == PREDATOR) {
        if (dest->getType() == PREDATOR) {
            Cell* strongestPredator = roulette(cell, dest);
            if (strongestPredator == cell) {
                (static_cast<Predator*>(
                        strongestPredator->getObject()
                ))->eat(dest);
            } else {
                (static_cast<Predator*>(
                        strongestPredator->getObject()
                ))->eat(cell);
                return;
            }
        } else {
            eat(dest);
        }
    }

    Cell* previousCell = cell;
    changeCell(dest);

    if (doReproduction(PREDATOR_REPRODUCTION_CYCLE)) {
        int minSize = 1;

        if (hasFriends) {
            minSize = getRandom(MAX_PREDATOR_SIZE / 2);
        }
        Object* object = new Predator(previousCell, minSize);
        previousCell->setObject(object);
        previousCell->addToStuff(object);
    }
}

void Predator::eat(Cell* cell) {
    satiety += cell->getObject()->getSize() * FOOD_EFFECTIVENESS;
    cell->getObject()->death();
}

Cell *Predator::minPredator(Cell *cell1, Cell *cell2) {
    if (cell1->getObject()->getSize() > cell2->getObject()->getSize()) {
        return cell2;
    } else {
        return cell1;
    }
}

Cell *Predator::roulette(Cell *predator1, Cell *predator2) {
    Cell* max = maxPredator(predator1, predator2);
    Cell* min = minPredator(predator1, predator2);
    int sizeMin = min->getObject()->getSize();
    int sizeMax = max->getObject()->getSize();

    int roulette = getRandom(sizeMin + sizeMax);

    if (roulette < sizeMin) {
        return min;
    } else {
        return max;
    }
}

Cell *Predator::maxPredator(Cell *cell1, Cell *cell2) {
    if (cell1->getObject()->getSize() > cell2->getObject()->getSize()) {
        return cell1;
    } else {
        return cell2;
    }
}
