// Copyright 2021 Artem Danyaev
#include <ctime>
#include "../include/ocean.h"
#include "../include/object.h"
#include "../include/predator.h"
#include "../include/prey.h"
#include "../include/stone.h"

Ocean::Ocean() {
    cells = new Cell * [M];
    for (int i = 0; i < M; i++) {
        Cell* tcells = new Cell[N];
        for (int j = 0; j < N; j++) {
            tcells[j].init(Pair{ i, j }, this);
        }
        cells[i] = tcells;
    }
}

void Ocean::addObjects() {
    unsigned int seed = time(nullptr);
    for (int i = 0; i < numStones; i++) {
        int x = rand_r(&seed) % M;
        int y = rand_r(&seed) % N;
        while (cells[x][y].getObject() != nullptr) {
            x = rand_r(&seed) % M;
            y = rand_r(&seed) % N;
        }
        Stone* obj = new Stone(&cells[x][y]);
        cells[x][y].setObject(obj);
        stuff.push_back(obj);
    }

    for (int i = 0; i < numPreys; i++) {
        int x = rand_r(&seed) % M;
        int y = rand_r(&seed) % N;
        while (cells[x][y].getObject() != nullptr) {
            x = rand_r(&seed) % M;
            y = rand_r(&seed) % N;
        }
        Prey* obj = new Prey(&cells[x][y]);
        cells[x][y].setObject(obj);
        stuff.push_back(obj);
    }

    for (int i = 0; i < numPredators; i++) {
        int x = rand_r(&seed) % M;
        int y = rand_r(&seed) % N;
        while (cells[x][y].getObject() != nullptr) {
            x = rand_r(&seed) % M;
            y = rand_r(&seed) % N;
        }
        Predator* obj = new Predator(&cells[x][y]);
        cells[x][y].setObject(obj);
        stuff.push_back(obj);
    }
}


int Ocean::countPredators() const {
    int i = 0;
    for (Object* o : stuff) {
        if (o->getType() == ObjType::PREDATOR) {
            i++;
        }
    }
    return i;
}


int Ocean::countPreys() const {
    int i = 0;
    for (Object* o : stuff) {
        if (o->getType() == ObjType::PREY) {
            i++;
        }
    }
    return i;
}


void Ocean::print() const {
    // system("cls");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cells[j][i].getObject() == nullptr) {
                std::cout << ' ';
            } else if (cells[j][i].getObject()->getType() == ObjType::STONE) {
                std::cout << STONE_N;
            } else if (cells[j][i].getObject()->getType() == ObjType::PREY) {
                std::cout << PREY_N;
            } else if (cells[j][i].getObject()->getType()
                            == ObjType::PREDATOR) {
                std::cout << PREDATOR_N;
            }
        }
        std::cout << std::endl;
    }
    std::cout << "Number of preys: " << countPreys() << std::endl;
    std::cout << "Number of predators: " << countPredators() << std::endl;
}

void Ocean::run() {
    int i = 0;
    while (!stuff.empty()) {
        print();
        std::cout << "Number of iteration: " << i << std::endl;
        // Sleep(100);
        for (Object* o : stuff) {
            o->live();
        }
        for (Object* o : stuffToBeKilled) {
            if (o) {
                stuff.remove(o);
            }
        }
        stuffToBeKilled.clear();
        i++;
    }
    print();
}

Cell* Ocean::getCell(Pair crd) { return &cells[crd.x][crd.y]; }

void Ocean::addObject(Object* o) { stuff.push_back(o); }

void Ocean::deleteObject(Object* o) { stuffToBeKilled.push_back(o); }
