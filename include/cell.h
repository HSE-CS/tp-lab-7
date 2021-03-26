// Copyright 2021 Golovanov
#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include "../include/common.h"
#include "../include/object.h"
#include "../include/ocean.h"

class Ocean;

class Cell {
    friend Ocean;
 private:
    Pair crd;
    Object* obj;
    Ocean* ocean;
 public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
        crd(p),
        obj(nullptr),
        ocean(oc) {}

    void init(Pair p, Ocean* oc);
    Object* getObject() const;
    void setObject(Object* object_);
    void killMe();

    void setOcean(Ocean* ocean_);
    Ocean* getOcean();
    Cell* seachEmptyPlace();
    Cell* hunt();
};

#endif  // INCLUDE_CELL_H_
