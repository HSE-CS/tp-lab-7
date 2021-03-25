#include "../include/Ocean.h"
#include "../include/cell.h"
#include "../include/stone.h"
#include "../include/prey.h"
#include "../include/predator.h"

Ocean::Ocean() {
    this->water.resize(height);
    for (int i = 0; i < height; ++i) {
        water[i].resize(width);
    }
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            this->water[i][j] = new Cell(j, i, nullptr, this);
        }
    }
}

void Ocean::renderOcean() {
    system("clear");
    for (const auto &a : water) {
        for (auto b : a) {
            std::cout << b->getObject()->getFiller();
        }
    }
}

void Ocean::init(int stones, int preys, int predators) {
    std::random_device basic;

    for (int i = 0; i < stones; ++i) {
        auto newStone = new stone(static_cast<signed>(basic()) % width,
                                  static_cast<signed>(basic()) % height,
                                  STONE,
                                  -1);
        newStone->setCell(getCell(newStone->getX(), newStone->getY()));
        this->water[newStone->getY()][newStone->getX()]->setObject(newStone);
    }
    for (int i = 0; i < preys; ++i) {
        auto newPrey = new prey(static_cast<signed>(basic()) % width,
                                static_cast<signed>(basic()) % height,
                                PREY,
                                startPreyEnergy);
        newPrey->setCell(getCell(newPrey->getX(), newPrey->getY()));
        this->water[newPrey->getY()][newPrey->getX()]->setObject(newPrey);
    }
    for (int i = 0; i < predators; ++i) {
        auto newPredator = new prey(static_cast<signed>(basic()) % width,
                                    static_cast<signed>(basic()) % height,
                                    PREDATOR,
                                    startPredatorEnergy);
        newPredator->setCell(getCell(newPredator->getX(), newPredator->getY()));
        this->water[newPredator->getY()][newPredator->getX()]->setObject(newPredator);
    }
}

bool Ocean::isConditionOkay() {
    int predators = 0, preys = 0;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (water[i][j]->getObject()->getType() == PREDATOR) {
                predators++;
            }
            if (water[i][j]->getObject()->getType() == PREY) {
                preys++;
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

    }
}
