// Copyright Mushka Nikita 2021

#ifndef _CELL_H_
#define _CELL_H_

#include "common.h"
#include "object.h"
#include "ocean.h"

#include <vector>

class Ocean;

class Cell {
    friend Ocean;

private:
    Pair crd{};
    Object *obj;
    Ocean *ocean;

public:
    explicit Cell(
            Pair new_pair = {0, 0},
            Ocean *new_ocean = nullptr, int check = 1);

    [[nodiscard]] Object *getObject() const;

    void setObject(Object *object);

    void setOcean(Ocean *new_ocean);

    Pair getCoords () { return crd;}

    Ocean * getOcean();

    Cell * findPlaceToMove();

    Cell *findPrey();

    static std::vector<Pair> findNeighbourCoords(Pair pair);

};

#endif
