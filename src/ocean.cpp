// Copyright 2021 Khoroshavina Ekaterina
#include "ocean.h"
#include <time.h>
#include <iostream>
#include <cstdlib>

Ocean::Ocean() {
    cells = new Cell * [N];
    for (auto i = 0; i < N; i++) {
        cells[i] = new Cell[M];
        for (auto j = 0; j < M; j++) {
            cells[i][j].init(Pair{ i, j }, this);
        }
    }
}

Ocean::~Ocean() {
    for (int i = 0; i < N; i++) {
        delete[] cells[i];
    }
    delete[] cells;
}

void Ocean::makeOcean(int numPrey, int numPredator, int numStone) {
    int countPrey = numPrey;
    int countPredator = numPredator;
    int countStone = numStone;
    for (int i = numPrey + numPredator + numStone; i > 0; i--) {
        unsigned int seed = time(nullptr);
        unsigned int x = rand_r(&seed) % M;
        unsigned int y = rand_r(&seed) % N;
        if (cells[y][x].getObject()) {
            i++;
            continue;
        } else {
            Object* obj = nullptr;
            if (countPrey > 0) {
               obj = new Prey(ObjType::PREY, &cells[y][x]);
                countPrey--;
            } else if (countPredator > 0) {
                obj = new Predator(ObjType::PREDATOR, &cells[y][x]);
                countPredator--;
            } else if (countStone > 0) {
                obj = new Stone(ObjType::STONE, &cells[y][x]);
            }
            cells[y][x].setObject(obj);
            stuff.push_back(obj);
        }
    }
}

void Ocean::print() const {
    for (auto i = 0; i < N; i++) {
        for (auto j = 0; j < M; j++) {
            if (cells[i][j].getObject()) {
                ObjType type = cells[i][j].getObject()->getType();
                if (type == ObjType::PREY) {
                    std::cout << PREY_N;
                } else if (type == ObjType::PREDATOR) {
                    std::cout << PREDATOR_N;
                } else if (type == ObjType::STONE) {
                    std::cout << STONE_N;
                }
            } else {
                std::cout << '.';
            }
        }
        std::cout << std::endl;
    }
}

void Ocean::addObject(Object* newObj) {
    stuff.push_back(newObj);
}

void Ocean::run() {
    while (true) {
        std::cout << "\x1b[0m";
        clock_t now = clock();
        print();
        std::cout << "======================================" << std::endl;
        while (clock() < now + CLOCKS_PER_SEC / 10) {
            continue;
        }
        for (std::list<Object*>::iterator i = stuff.begin();
            i != stuff.end(); ++i) {
            if ((*i) != nullptr) {
                if (!((*i)->isAlive())) {
                    (*i)->getCell()->killMe();
                } else {
                    (*i)->live();
                }
            }
        }
    }
}

Cell* Ocean::newCell(Pair crd) {
    //int new_x = (crd.x + rand() % 2) % N;
    //int new_y = (crd.y + rand() % 2) % M;
    unsigned int seed = time(nullptr);
    int new_x = (crd.x + rand_r(&seed) % 2) % N;
    int new_y = (crd.y + rand_r(&seed) % 2) % M;
    return &(this->cells[new_x][new_y]);
}