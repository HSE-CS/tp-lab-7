

#include "ocean.h"
#include <ctime>
#include <iostream>
#include <cstdlib>
#include <predator.h>
#include <stone.h>

Ocean::Ocean(unsigned int new_size) {
    this->size = new_size;
    this->cells = new Cell *[new_size];
    for (int i = 0; i < new_size; i++) this->cells[i] = new Cell[new_size];

    for (unsigned int i = 0; i < new_size; i++) {
        for (unsigned int j = 0; j < new_size; j++) {
            Cell new_cell = Cell({i, j}, this);
            this->cells[i][j] = new_cell;
        }
    }
}

void Ocean::print() const {
    for (unsigned int i = 0; i < this->size; i++) {
        for (unsigned int j = 0; j < this->size; j++) {
            std::cout << ' ';
            if (this->cells[i][j].getObject()) {
                std::cout << this->cells[i][j].getObject()->getSymbol();
            } else {
                std::cout << '.';
            }
            std::cout << ' ';
        }
        std::cout << '\n';
    }
    std::cout << std::endl << std::endl << std::endl;
}

unsigned int Ocean::getSize() const {
    unsigned int len = this->size;
    return size;
}

void Ocean::FillWithRandomObjects() {

    std::srand(std::time(nullptr));
    unsigned int len = this->size;

    for (unsigned int i = 0; i < len * len; i++) {
        unsigned int x = i / len, y = i % len;
        int index = std::rand() % 7 + 1;
        Object *obj = nullptr;
        if (index < 3) {
            Cell cell = this->cells[x][y];
            if (index == 0) obj = new Predator(&cell);
            else if (index == 1) obj = new Prey(&cell);
            else obj = new Stone(&cell);
            this->objects.push_back(obj);
        }
        this->cells[x][y].setObject(obj);
    }
}

void Ocean::start() {
    this->print();
    for (int i = 0; i < 500; i++) {
        for (int j = 0; j < this->objects.size(); j++) {
            objects[j]->step();
            std::cout << j << ' ';
        }
    }
}


void Ocean::addObject(Object *obj) {
    this->objects.push_back(obj);
}


Object *Ocean::getObject(Pair pair) {
    return this->objects[pair.x * this->size + pair.y];
}


Cell *Ocean::getCell(Pair pair) {
    return this->cells[pair.x * this->size + pair.y];
}
