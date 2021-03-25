//  Copyright 2021 Nikita Naumov

#include "../include/ocean.h"

Ocean::Ocean() {
    Pair p_new;
    this->cells = new Cell* [N];
    for (size_t i = 0; i < N; ++i) {
        this->cells[i] = new Cell [M];
    }
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            p_new.x = i; p_new.y = j;
            this->cells[i][j] = Cell(p_new, this);
        }
    }
}

Ocean::~Ocean() {
    for (size_t i = 0; i < N; ++i) {
        delete[] this->cells[i];
    }
    delete[] this->cells;
}

void Ocean::run() {
    while (true) {
        for (size_t i = 0; i < N; ++i) {
            for (size_t j = 0; j < M; ++j) {
                this->cells[i][j].object->live();
            }
        }
    }
}
void Ocean::addObjects() {

}
void Ocean::print() const {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            std::cout << "{" << this->cells[i][j].coordinates.x <<
                      ";" << this->cells[i][j].coordinates.y << "}\t";
        }
        std::cout << std::endl;
    }
}
