// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_

#include <vector>
#include "../include/common.h"
#include "../include/object.h"
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
        ocean(oc) {}
    Pair getCrd();
    Object* getObject() const;
    void setObject(Object*);
    void killMe();
    vector<Cell*>* getEmptyCells();
    void addToOcean(Object*);
    vector<Cell*>* getPreyCells();
};

#endif  // INCLUDE_CELL_H
