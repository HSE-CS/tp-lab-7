// Copyright 2021 Nikolaev Ivan

#ifndef INCLUDE_CELL_H_
#define INCLUDE_CELL_H_
#include <string>
#include "../include/common.h"
#include "../include/object.h"

class Ocean;

class Cell {
    friend Ocean;
 private:
    Pair crd;
    Object* obj;
    Ocean* ocean;
    char symbol = '~';
 public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
        crd(p),
        obj(nullptr),
        ocean(oc) {}
    void init(Pair p, Ocean* oc);
    Ocean* getOcean();
    Object* getObject();
    void setObject(Object* obj);
    char getSymbol();
    Pair getCrd();
    void setCrd(Pair crd);
};

#endif  // INCLUDE_CELL_H_
