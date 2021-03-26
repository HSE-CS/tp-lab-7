// copyright 2021 Victor Shatilov

#include "../include/Ocean.h"
#include "../include/cell.h"
#include "../include/stone.h"
#include "../include/prey.h"
#include "../include/predator.h"

#include<unistd.h>

Ocean::Ocean() {
    this->water.resize(height);
    for (int i = 0; i < height; ++i) {
        water[i].resize(width);
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            this->water[i][j] = new Cell(j, i,
                                         nullptr, this);
        }
    }
}

void Ocean::renderOcean() {
    for (const auto &a : water) {
        for (auto b : a) {
            if (b->getObject() != nullptr)
                std::cout << b->getObject()->getFiller();
            else
                std::cout << void_symbol;
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void Ocean::init(int stones, int preys, int predators) {
    std::random_device basic;

    for (int i = 0; i < stones; ++i) {
        auto newStone = new stone(basic() % width,
                                  basic() % height,
                                  -1,
                                  STONE);
        newStone->setCell(getCell(
                newStone->getX(), newStone->getY()));
        this->water[newStone->getY()][
                newStone->getX()]->setObject(newStone);
    }
    for (int i = 0; i < preys; ++i) {
        auto newPrey = new prey(basic() % width,
                                basic() % height,
                                startPreyEnergy,
                                PREY);
        newPrey->setCell(getCell(newPrey->getX(), newPrey->getY()));
        this->water[newPrey->getY()][newPrey->getX()]->setObject(newPrey);
    }
    for (int i = 0; i < predators; ++i) {
        auto newPredator = new predator(basic() % width,
                                        basic() % height,
                                        startPredatorEnergy,
                                        PREDATOR);
        newPredator->setCell(getCell(
                newPredator->getX(), newPredator->getY()));
        this->water[newPredator->getY()][
                newPredator->getX()]->setObject(newPredator);
    }
}

bool Ocean::isConditionOkay() {
    int predators = 0, preys = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (water[i][j]->getObject() != nullptr) {
                if (water[i][j]->getObject()->getType() == PREDATOR) {
                    predators++;
                }
                if (water[i][j]->getObject()->getType() == PREY) {
                    preys++;
                }
            }
        }
    }

    if (predators == 0 || preys == 0) {
        return false;
    }
    return true;
}

void Ocean::run(int iterations) {
    while (iterations--) {
        this->renderOcean();
        sleep(1);
        if (!isConditionOkay())
            break;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                if (water[i][j]->getObject() != nullptr) {
                    auto thisObj = water[i][j]->getObject();
                    thisObj->live();
                    if (thisObj->getEnergy() >= 2 * startPreyEnergy) {
                        auto child = thisObj->divide();
                    }
                }
            }
        }
    }
}

Cell *Ocean::getCell(int x, int y) {
    return water[y][x];
}
