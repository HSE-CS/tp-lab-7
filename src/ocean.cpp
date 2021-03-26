// Copyright 2020 Osmanov Islam

#include <time.h>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <random>
#include <vector>
#include "../include/ocean.h"

Ocean::~Ocean() {
    delete[] cells;
    for (Object* element : animals) {
        delete element;
    }
}

Ocean::Ocean(float preyPercentage,
             float predatorPercentage,
             float stonePercentage) {
    cells = new Cell * [N];
    for (int i = 0; i < N; i++) {
        cells[i] = new Cell[M];
        for (int j = 0; j < M; j++) {
            cells[i][j].init({ i, j }, this);
        }
    }
    std::minstd_rand simple_rand;

    for (int i = 0; i < static_cast<int>(preyPercentage * N * M); i++) {
        while (true) {
            simple_rand.seed(time(nullptr));
            int x = simple_rand() % N;
            int y = simple_rand() % M;
            if (cells[x][y].obj == nullptr) {
                Prey* curPrey = new Prey(&cells[x][y]);
                cells[x][y].obj = curPrey;
                animals.push_back(curPrey);
                break;
            }
        }
    }

    for (int i = 0; i < static_cast<int>(predatorPercentage * N * M); i++) {
        while (true) {
            simple_rand.seed(time(nullptr));
            int x = simple_rand() % N;
            int y = simple_rand() % M;

            if (cells[x][y].obj == nullptr) {
                Predator* pred = new Predator(&cells[x][y]);
                cells[x][y].obj = pred;
                animals.push_back(pred);
                break;
            }
        }
    }

    for (int i = 0; i < static_cast<int>(stonePercentage * N * M); i++) {
        while (true) {
            simple_rand.seed(time(nullptr));
            int x = simple_rand() % N;
            int y = simple_rand() % M;
            if (cells[x][y].obj == nullptr) {
                Stone* currStone = new Stone(&cells[x][y]);
                cells[x][y].obj = currStone;
                animals.push_back(currStone);
                break;
            }
        }
    }
}

Cell* Ocean::findCell(Cell* cell) {
    std::minstd_rand simple_rand;
    simple_rand.seed(time(nullptr));
    return &cells[(cell->crd.x + simple_rand()) % N]
                 [(cell->crd.y + simple_rand()) % M];
}

void Ocean::addObject(Object* elem) {
    animals.push_back(elem);
}

void Ocean::print() const {
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < M; k++) {
            if (cells[i][k].getObject() == nullptr)
                std::cout << EMPTY_N;
            else if (cells[i][k].getObject()->getType() == PREY)
                std::cout << PREY_N;
            else if (cells[i][k].getObject()->getType() == PREDATOR)
                std::cout << PREDATOR_N;
            else if (cells[i][k].getObject()->getType() == STONE)
                std::cout << STONE_N;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}


void Ocean::run() {
    int t = 0;
    while (t < 3) {
        for (Object* object : animals) {
            if (object == nullptr)
                continue;
            object->live();
        }
        print();
        t++;
    }
}
