// Copyright JMax 2021

#include <ctime>
#include <iostream>
#include <vector>
#include <map>
// #include <accctrl.h>

#include "../include/Ocean.h"
#include "../include/Stone.h"
#include "../include/Prey.h"
#include "../include/Predator.h"

Ocean::Ocean() {
    makeOcean();
    createSpecies();
}

void Ocean::makeOcean() {
    cells = new Cell*[OCEAN_Y_SIZE];
    for (int i = 0; i < OCEAN_Y_SIZE; i++) {
        cells[i] = new Cell[OCEAN_X_SIZE];
        for (int j = 0; j < OCEAN_X_SIZE; j++) {
            cells[i][j].init({j, i}, this);
        }
    }
}

void Ocean::createSpecies() {
    std::map<objectType, int> species = {
            {STONE, STONE_DEFAULT_POPULATION},
            {PREY, PREY_DEFAULT_POPULATION},
            {PREDATOR, PREDATOR_DEFAULT_POPULATION}
    };

    bool clear = true;
    while (clear) {
        clear = false;
        for (const auto &i : species) {
            if (i.second == 0) {
                species.erase(i.first);
                clear = true;
                break;
            }
        }
    }

    while (true) {
        std::vector<Cell*> emptyCells = getEmptyCells();
        if (species.empty() || emptyCells.empty()) {
            break;
        }
        int idx = getRandom(species.size());

        Cell* cell = emptyCells[getRandom(emptyCells.size())];

        for (const auto& i : species) {
            if (--idx < 0) {
                Object* object = getObject(i.first, cell);
                cell->setObject(object);
                stuff.push_back(object);
                if (i.second <= 1) {
                    species.erase(i.first);
                } else {
                    species[i.first]--;
                }
                break;
            }
        }
    }
}

int Ocean::getRandom(int max) {
    unsigned int seed = time(nullptr);
    return rand_r(&seed) % max;
}

std::vector<Cell*> Ocean::getEmptyCells() const {
    std::vector<Cell*> emptyCells;
    for (int i = 0; i < OCEAN_Y_SIZE; i++) {
        for (int j = 0; j < OCEAN_X_SIZE; j++) {
            if (cells[i][j].getType() == NOTHING) {
                emptyCells.push_back(&cells[i][j]);
            }
        }
    }
    return emptyCells;
}

Object *Ocean::getObject(objectType type, Cell* cell) {
    Object *object = nullptr;
    switch (type) {
        case STONE:
            object = new Stone(cell);
            break;
        case PREY:
            object = new Prey(cell);
            break;
        case PREDATOR:
            object = new Predator(cell);
            break;
    }
    return object;
}

void Ocean::printOcean() const {
    std::cout << "Ocean (" << step << " step)" << std::endl;
    for (int i = 0; i < OCEAN_Y_SIZE; i++) {
        for (int j = 0; j < OCEAN_X_SIZE; j++) {
            std::cout << cells[i][j].getSymbol();
        }
        std::cout << std::endl;
    }
}

void Ocean::clearStuff() {
    bool clear = true;
    stuff.unique();
    while (clear) {
        auto i = stuff.begin();
        clear = false;
        for (const auto &object : stuff) {
            if (!object->isAlive()) {
                delete object;
                stuff.erase(i);
                clear = true;
                break;
            }
            i++;
        }
    }
}

std::map<std::string, int> Ocean::calcStuff() const {
    std::map<std::string, int> species = {{"Stone", 0},
                                          {"Prey", 0},
                                          {"Predator", 0}};
    for (auto i : stuff) {
        objectType type = i->getType();
        switch (type) {
            case STONE:
                species["Stone"]++;
                break;
            case PREY:
                species["Prey"]++;
                break;
            case PREDATOR:
                species["Predator"]++;
                break;
        }
    }

    return species;
}

Ocean::~Ocean() {
    for (int i = 0; i < OCEAN_Y_SIZE; i++) {
        delete[] cells[i];
    }
    delete[] cells;
}

Cell *Ocean::getCell(Pair crd) {
    int y = crd.y % OCEAN_Y_SIZE;
    if (y < 0) {
        y = OCEAN_Y_SIZE + y;
    }
    int x = crd.x % OCEAN_X_SIZE;
    if (x < 0) {
        x = OCEAN_X_SIZE + x;
    }
    return &cells[y][x];
}

void Ocean::run() {
    bool run = true;

    clearStuff();
    printOcean();
    std::map<std::string, int> stats = calcStuff();
    printStats(stats);

    while (run) {
        step++;
        for (auto& i : stuff) {
            i->live();
        }
        clearStuff();
        printOcean();
        std::map<std::string, int> stats = calcStuff();
        printStats(stats);

        if (stats["Predator"] == 0) {
                run = false;
        }
    }
    std::cout << "Stop" << std:: endl;
}

void Ocean::printStats(std::map<std::string, int> stats) {
    for (auto const& i : stats) {
        std::cout << i.first << ": " << i.second << " ";
    }
    std::cout << std::endl;
}

void Ocean::addToStuff(Object *object) {
    stuff.push_back(object);
}
