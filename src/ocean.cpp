
#include "../include/ocean.h"

Ocean::Ocean(unsigned int x_len, unsigned int y_len) {
    if (x_len < 1 || y_len < 1) {
        throw "X or Y out of range";
    }
    this->cells.resize(x_len);
    for (std::vector<Cell *> &a : this->cells) {
        a.resize(y_len);
    }
}

Ocean::~Ocean() {
    for (auto & cell : this->cells) {
        for (auto & j : cell) {
            delete j;
        }
    }
    for (Object *a: this->stuff) {
        delete a;
    }
}

void Ocean::addObjects(std::list<Object *> lst) {
    this->stuff.insert(this->stuff.end(), lst.begin(), lst.end());
}

Cell * Ocean::get(unsigned int x, unsigned int y) {
    if (x < 0 || y < 0 ||
    x >= this->cells.size() || y >= this->cells[0].size()) {
        throw "X or Y out of range";
    }
    return this->cells[x][y];
}

unsigned int Ocean::lenX() {
    return this->cells.size();
}

unsigned int Ocean::lenY() {
    return this->cells[0].size();
}

Object * Ocean::removeFromStuff(Object *obj) {
    return nullptr;
}
