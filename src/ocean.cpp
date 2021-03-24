// Copyright 2021 Kasyanov
#include <string>
#include <chrono>
#include <thread>
#include "ocean.h"
#include "stone.h"

Ocean::Ocean() {
    cells = new Cell *[N];
    for (int i = 0; i < N; ++i) {
        cells[i] = new Cell[M];
    }
    addObjects();
}

Ocean::~Ocean() {
    for (int i = 0; i < N; ++i) {
        delete[] cells[i];
    }
    delete[] cells;
}

void Ocean::print() const {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            std::cout << cells[i][j];
        }
        std::cout << '\n';
    }
    std::cout << "==============================================================\n\n";
}

void Ocean::addObjects() {
    std::vector<int> vec(N * M);
    for (int i = 0; i < N * M; ++i) { vec[i] = i; }
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(vec.begin(), vec.end(), std::default_random_engine(seed));
    for (int m = 0; m < N * M; ++m) {
        int i = vec[m] / M;
        int j = vec[m] % M;
        cells[i][j].init({i, j}, this);
        if (m < N * M * 0.10) {
            auto *stone = new Stone(&cells[i][j]);
            cells[i][j].setObject(stone);
        } else if (m < N * M * 0.50) {
            auto *prey = new Prey(&cells[i][j]);
            cells[i][j].setObject(prey);
        } else if (m < N * M * 0.65) {
            auto *predator = new Predator(&cells[i][j]);
            cells[i][j].setObject(predator);
        }
    }
}

ObjType Ocean::getNear(int i, int j) const {
    if (!cells[i][j].getObject()) {
        return ObjType::CORAL;
    } else {
        return cells[i][j].getObject()->type;
    }
}

void Ocean::run() {
    while (true) {
        std::vector<int> vec(N * M);
        for (int i = 0; i < N * M; ++i) { vec[i] = i; }
        unsigned seed = std::chrono::system_clock::now().
                time_since_epoch().count();
        std::shuffle(vec.begin(), vec.end(), std::default_random_engine(seed));
        for (int m = 0; m < N * M; ++m) {
            int i = vec[m] / M;
            int j = vec[m] % M;
            auto obj = cells[i][j].getObject();
            if (obj) {obj->live();}
        }
        this->print();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}
