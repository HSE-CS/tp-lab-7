// Copyright 2021 Stifeev Nikita

#include <iostream>
#include <cstdlib>
#include <set>
#include "../include/ocean.h"
#include "../include/stone.h"
#include "../include/prey.h"
#include "../include/predator.h"
using std::cout;
using std::endl;

Ocean::Ocean() {
    cells = vector<vector<Cell*>>(M);
    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) {
            cells[i].push_back(new Cell(Pair{ i, j }, this));
        }
    }
    stuff = std::list<Object*>();
}

Ocean::~Ocean() {}

void Ocean::print() const {
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < M; j++) {
            if (cells[j][i]->getObject() != nullptr) {
                cout << cells[j][i]->getObject()->getSign();
            } else {
                cout << CORAL_SYMBOL;
            }
        }
        cout << endl;
    }
}

void Ocean::addObjects(ObjType type, size_t number) {
    for (size_t i = 0; i < number; i++) {
        int x = 0, y = 0;
        while (true) {
            x = std::rand() % M;
            y = std::rand() % N;
            if (cells[x][y]->getObject() == nullptr) {
                break;
            }
        }
        switch (type) {
        case ObjType::STONE: {
            Stone* stone = new Stone(cells[x][y], STONE_SYMBOL);
            cells[x][y]->setObject(stone);
            stuff.emplace_back(stone);
            break;
        }
        case ObjType::PREY: {
            Prey* prey = new Prey(cells[x][y], PREY_SYMBOL);
            cells[x][y]->setObject(prey);
            stuff.emplace_back(prey);
            break;
        }
        case ObjType::PREDATOR: {
            Predator* predator = new Predator(cells[x][y], PREDATOR_SYMBOL);
            cells[x][y]->setObject(predator);
            stuff.emplace_back(predator);
            break;
        }
        }
    }
}

void Ocean::addObject(Object* obj) {
    stuff.emplace_back(obj);
}

void Ocean::run() {
    toDelete = std::list<Object*>();
    size_t stoneCount = 0, preyCount = 0, predatorCount = 0;
    counter(stoneCount, preyCount, predatorCount);
    while (predatorCount > 0 && preyCount > 0 && stoneCount +
        preyCount + predatorCount < N * M) {
        cout << "Stone: " << stoneCount << "Prey: "
            << preyCount << "Predator: " << predatorCount << endl;
        toDelete.clear();
        for (auto* obj : stuff) {
            if (obj->getCell()) {
                if (!obj->live()) {
                    obj->getCell()->setObject(nullptr);
                    toDelete.push_back(obj);
                }
            }
        }
        print();
        for (auto* obj : toDelete) {
            stuff.remove(obj);
        }
        counter(stoneCount, preyCount, predatorCount);
    }
}

void Ocean::counter(size_t& stoneCount, size_t& preyCount,
    size_t& predatorCount) {
    stoneCount = 0;
    preyCount = 0;
    predatorCount = 0;
    for (Object* obj : stuff) {
        switch (obj->getSign()) {
        case STONE_SYMBOL:
            stoneCount++;
            break;
        case PREY_SYMBOL:
            preyCount++;
            break;
        case PREDATOR_SYMBOL:
            predatorCount++;
            break;
        }
    }
}

vector<Cell*>* Ocean::getEmptyCells(Cell* cell) {
    auto emptyCells = new vector<Cell*>();
    coord_t x = cell->getCrd().x;
    coord_t y = cell->getCrd().y;
    if (x + 1 < cells.size() && cells[x + 1][y]->getObject() == nullptr) {
        emptyCells->push_back(cells[x + 1][y]);
    }

    if (x >= 1 && cells[x - 1][y]->getObject() == nullptr) {
        emptyCells->push_back(cells[x - 1][y]);
    }

    if (y + 1 < cells[0].size() && cells[x][y + 1]->getObject() == nullptr) {
        emptyCells->push_back(cells[x][y + 1]);
    }

    if (y >= 1 && cells[x][y - 1]->getObject() == nullptr) {
        emptyCells->push_back(cells[x][y - 1]);
    }
    return emptyCells;
}

vector<Cell*>* Ocean::getCellsWithPrey(Cell* cell) {
    auto targetCells = new vector<Cell*>();
    coord_t x = cell->getCrd().x;
    coord_t y = cell->getCrd().y;
    if (x + 1 < cells.size() && cells[x + 1][y]->getObject() &&
        cells[x + 1][y]->getObject()->getSign() == PREY_SYMBOL) {
        targetCells->push_back(cells[x + 1][y]);
    }

    if (x >= 1 && cells[x - 1][y]->getObject() &&
        cells[x - 1][y]->getObject()->getSign() == PREY_SYMBOL) {
        targetCells->push_back(cells[x - 1][y]);
    }

    if (y + 1 < cells[0].size() && cells[x][y + 1]->getObject() &&
        cells[x][y + 1]->getObject()->getSign() == PREY_SYMBOL) {
        targetCells->push_back(cells[x][y + 1]);
    }

    if (y >= 1 && cells[x][y - 1]->getObject() &&
        cells[x][y - 1]->getObject()->getSign() == PREY_SYMBOL) {
        targetCells->push_back(cells[x][y - 1]);
    }
    return targetCells;
}

void Ocean::killObject(Cell* cell) {
    for (auto* obj : stuff) {
        if (obj == cell->getObject()) {
            obj->setCell(nullptr);
            toDelete.push_back(obj);
        }
    }
    cell->setObject(nullptr);
}
