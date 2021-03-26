// Copyright 2021 Artem Danyaev
#include <ctime>
#include "../include/object.h"

Object::Object(ObjType t, Cell* c) : type(t), cell(c) {}

void Object::setCell(Cell* c) { cell = c; }

bool Object::checkIfCellExists(Pair crd) {
    return ((crd.x >= 0 && crd.x < M) && (crd.y >= 0 && crd.y < N));
}

Cell* Object::findFreeNeighbour() {
    unsigned int seed = time(nullptr);
    std::vector<Pair> offsets;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            offsets.push_back(Pair{ i, j });
        }
    }
    while (!offsets.empty()) {
        int pos = rand_r(&seed) % offsets.size();
        Pair crd = cell->getCoords();
        Pair tcrd { crd.x + offsets[pos].x, crd.y + offsets[pos].y };
        if (checkIfCellExists(tcrd) &&
            cell->getOcean()->getCell(tcrd)->getObject() == nullptr) {
            return cell->getOcean()->getCell(tcrd);
        } else {
            offsets.erase(offsets.begin() + pos);
        }
    }
    return nullptr;
}

ObjType Object::getType() { return type; }
