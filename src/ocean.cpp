// Copyright 2021 Igumnova Natasha
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include "../include/ocean.h"

Ocean::Ocean(float preyP, float predatorP,
    float stoneP) {
    cells = new Cell * [N];
    for (int i = 0; i < N; i++) {
        cells[i] = new Cell[M];
        for (int j = 0; j < M; j++) {
            cells[i][j].init({ i, j }, this);
        }
    }
    int prey = static_cast<int>(preyP * N * M);
    int predator = static_cast<int>(predatorP * N * M);
    int stone = static_cast<int>(stoneP * N * M);
    for (int i = 0; i < prey; i++) {
        while (true) {
            int x = rand_r(prey) % N;
            int y = rand_r(prey) % M;
            if (cells[x][y].obj == nullptr) {
                Prey* new_prey = new Prey(&cells[x][y]);
                cells[x][y].obj = new_prey;
                stuff.push_back(new_prey);
                break;
            }
        }
    }
    for (int i = 0; i < predator; i++) {
        while (true) {
            int x = rand_r(predator) % N;
            int y = rand_r(predator) % M;
            if (cells[x][y].obj == nullptr) {
                Predator* new_pred = new Predator(&cells[x][y]);
                cells[x][y].obj = new_pred;
                stuff.push_back(new_pred);
                break;
            }
        }
    }
    for (int i = 0; i < stone; i++) {
        while (true) {
            int x = rand_r(stone) % N;
            int y = rand_r(stone) % M;
            if (cells[x][y].obj == nullptr) {
                Stone* new_stone = new Stone(&cells[x][y]);
                cells[x][y].obj = new_stone;
                stuff.push_back(new_stone);
                break;
            }
        }
    }
}
Ocean::~Ocean() {
    delete[] cells;
    for (Object* i : stuff) {
        delete i;
    }
}
void Ocean::print() const {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cells[i][j].getObject() == nullptr)
                std::cout << "-";
            else if (cells[i][j].getObject()->getType() == STONE)
                std::cout << STONE_N;
            else if (cells[i][j].getObject()->getType() == PREY)
                std::cout << PREY_N;
            else if (cells[i][j].getObject()->getType() == PREDATOR)
                std::cout << PREDATOR_N;
        }
        std::cout << "\n";
    }
}
void Ocean::addObject(Object* elem) {
    stuff.push_back(elem);
}
void Ocean::run() {
    while (true) {
        for (Object* o : stuff) {
            if (o == nullptr)
                continue;
            std::cout << o->getType();
            o->live();
        }
        print();
    }
}
Cell* Ocean::findCell(Cell* cell) {
    int x = (cell->getX() + rand_r(100)) % N;
    int y = (cell->getY() + rand_r(100)) % M;
    return &cells[x][y];
}
