// Copyright 2021 BekusovMikhail

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "common.h"
#include "object.h"
#include "ocean.h"

class Ocean;

class Cell {
    friend Ocean;
 private:
    Pair crd;
    Object *obj;
    Ocean *ocean;
 public:
    explicit Cell(Pair p = {0, 0}, Ocean *oc = nullptr) :
            crd(p),
            obj(nullptr),
            ocean(oc) {}

    void init(Pair p, Ocean *oc);

    Object *getObject() const;

    void setObject(Object *obj);

    void killMe();

    void setOcean(Ocean *ocean);

    Ocean *getOcean();

    Cell *findEmptyCell();

    Cell *findPrey();

};

#endif  // INCLUDE_CELL_H_
