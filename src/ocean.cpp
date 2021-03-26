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
    std::cout << "Return later, i'm busy" << std::endl;
}
void Ocean::addObjects() {
    for (size_t i = 0; i < N; ++i) {
        for (size_t j = 0; j < M; ++j) {
            if (!(cells[i][j].isFree())) {
                stuff.push_back(cells[i][j].getObject());
            }
        }
    }
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

std::vector<Cell> Ocean::getNearbyCells(int i, int j) {
    std::vector<Cell> nearby;
    if ( i == 0 ) {
        if (j == 0) {
            nearby.push_back(this->cells[i+1][j]);
            nearby.push_back(this->cells[i+1][j+1]);
            nearby.push_back(this->cells[i][j+1]);
        } else if ( j == (M-1)) {
            nearby.push_back(this->cells[i+1][j]);
            nearby.push_back(this->cells[i+1][j-1]);
            nearby.push_back(this->cells[i][j-1]);
        } else {
            nearby.push_back(this->cells[i][j-1]);
            nearby.push_back(this->cells[i][j+1]);
            nearby.push_back(this->cells[i+1][j-1]);
            nearby.push_back(this->cells[i+1][j]);
            nearby.push_back(this->cells[i+1][j+1]);
        }
    } else if ( i == (N-1)) {
        if (j == 0) {
            nearby.push_back(this->cells[i-1][j]);
            nearby.push_back(this->cells[i-1][j+1]);
            nearby.push_back(this->cells[i][j+1]);
        } else if ( j == (M-1)) {
            nearby.push_back(this->cells[i-1][j]);
            nearby.push_back(this->cells[i-1][j-1]);
            nearby.push_back(this->cells[i][j-1]);
        } else {
            nearby.push_back(this->cells[i][j-1]);
            nearby.push_back(this->cells[i][j+1]);
            nearby.push_back(this->cells[i-1][j-1]);
            nearby.push_back(this->cells[i-1][j]);
            nearby.push_back(this->cells[i-1][j+1]);
        }
    } else if (j == 0 ) {
        if ((i > 0)  && (i < (N-1))) {
            nearby.push_back(this->cells[i - 1][j]);
            nearby.push_back(this->cells[i + 1][j]);
            nearby.push_back(this->cells[i - 1][j + 1]);
            nearby.push_back(this->cells[i][j + 1]);
            nearby.push_back(this->cells[i + 1][j + 1]);
        }
    } else if (j == (M-1)) {
        if ((i > 0)  && (i < (N-1))) {
            nearby.push_back(this->cells[i-1][j]);
            nearby.push_back(this->cells[i+1][j]);
            nearby.push_back(this->cells[i-1][j-1]);
            nearby.push_back(this->cells[i][j-1]);
            nearby.push_back(this->cells[i+1][j-1]);
        }
    } else if ((i > 0) && (i < (N-1)) && (j > 0) && (j < (M-1))) {
        nearby.push_back(this->cells[i-1][j-1]);
        nearby.push_back(this->cells[i-1][j]);
        nearby.push_back(this->cells[i-1][j+1]);
        nearby.push_back(this->cells[i][j-1]);
        nearby.push_back(this->cells[i][j+1]);
        nearby.push_back(this->cells[i+1][j-1]);
        nearby.push_back(this->cells[i+1][j]);
        nearby.push_back(this->cells[i+1][j+1]);
    }
    return nearby;
}
void Ocean::setObjectToCell(Object* object, int i, int j) {
    this->cells[i][j].setObject(object);
}

Cell* Ocean::getCell(int i, int j) {
    return &(this->cells[i][j]);
}