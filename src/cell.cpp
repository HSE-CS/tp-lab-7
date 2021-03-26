#include "cell.h"
#include <iostream>

Cell::Cell(Pair p, Ocean *oc, int ch) {
    this->crd = p;
    this->obj = nullptr;
    this->ocean = oc;
}


void Cell::setObject(Object *object) {
    this->obj = object;
}

Object *Cell::getObject() const {
    return this->obj;
}


void Cell::setOcean(Ocean *new_ocean) {
    this->ocean = new_ocean;
}

Ocean * Cell::getOcean() {
    return ocean;
}

Cell * Cell::findPlaceToMove() {

    this->getOcean()->print();
    unsigned int len = this->getOcean()->getSize() - 1;
    std::cout << len;
    for (int i = 0; i < len; i++) {
        std::cout << i << ' ';
    }
    std::vector<Pair> all_coords = findNeighbourCoords(this->crd);

    std::vector<Pair> coords;
    for (auto i = 0; i < 4; i++) {
        if (all_coords[i].x < 0 || all_coords[i].x > len ||
            all_coords[i].y < 0 || all_coords[i].y > len ||
            ! this->getOcean()->getObject(all_coords[i])) {
            coords.push_back(coords[i]);
        }
    }

    Pair toReturn = coords[std::rand() % coords.size()];
    return this->getOcean()->getCell(toReturn);

}

Cell *Cell::findPrey() {
    unsigned int x = this->crd.x, y = this->crd.y;
    unsigned int len = this->getOcean()->getSize() - 1;

    std::vector<Pair> all_coords;
    all_coords[0] = {x + 2, y};
    all_coords[1] = {x - 2, y};
    all_coords[2] = {x, y + 2};
    all_coords[3] = {x, y - 2};

    for (int i = 0; i < 4; i++) {
        std::vector<Pair> new_coords = findNeighbourCoords(all_coords[i]);
        for (int j = 0; j < 4; j++) {
            all_coords.push_back(new_coords[j]);
        }
    }

    all_coords.push_back({x + 1, y + 1});
    all_coords.push_back({x + 1, y - 1});
    all_coords.push_back({x - 1, y + 1});
    all_coords.push_back({x - 1, y - 1});

    for (auto &all_coord : all_coords) {
        if (this->getOcean()->getObject(all_coord)->getSymbol() == '*') {
            return this->getOcean()->getCell(all_coord);
        }
    }

    return nullptr;
}

std::vector<Pair> Cell::findNeighbourCoords(Pair pair) {
    unsigned int x = pair.x, y = pair.y;
    std::vector<Pair> all_coords;
    all_coords[0] = {x + 1, y};
    all_coords[1] = {x - 1, y};
    all_coords[2] = {x, y + 1};
    all_coords[3] = {x, y - 1};

    return all_coords;
}


