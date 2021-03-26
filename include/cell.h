// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_CELL_H
#define INCLUDE_CELL_H

#include "../include/common.h"
#include "../include/object.h"
#include <vector>
using std::vector;

class Ocean;

class Cell {
    friend Ocean;
 private:
    Pair crd;
    Object* obj;
    Ocean* ocean;
 public:
    explicit Cell(Pair p, Ocean* oc) :
        crd(p),
        obj(nullptr),
        ocean(oc) {};
    Pair getCrd();
    Object* getObject() const;
    void setObject(Object*);
    void killMe();
    vector<Cell*>* getEmptyCells();
    void addToOcean(Object*);
    vector<Cell*>* getPreyCells();
};

#endif  // INCLUDE_CELL_H
