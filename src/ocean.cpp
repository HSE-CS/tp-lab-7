// Copyright [2020] <Olesya Nikolaeva>

#include "ocean.h"

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

void Ocean::print() const {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (cells[i][j].getObject() == nullptr) {
                std::cout << EMPTY_N;
            } else if (cells[i][j].getObject()->getObjType() == ObjType::STONE) {
                std::cout << STONE_N;
            } else if (cells[i][j].getObject()->getObjType() == ObjType::PREY) {
                std::cout << PREY_N;
            } else if (cells[i][j].getObject()->getObjType() == ObjType::PREDATOR) {
                std::cout << PREDATOR_N;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Ocean::addObjects(Object* new_object) {
    stuff.push_back(new_object);
}

void Ocean::run() {
    
}

bool Ocean::returnCellStatus(Pair arg) {
    return cells[arg.x][arg.y].isfree;
}

Cell* Ocean::returnCell(Pair arg) {
    return &cells[arg.x][arg.y];
}
